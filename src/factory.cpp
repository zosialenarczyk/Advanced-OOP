// 35: Rafa (401991) Szota(401281)  Lenarczyk(402763)

#include "factory.hpp"
#include "cassert"


void Factory::add_ramp(Ramp && new_ramp)
{
    Ramps.add_node(std::move(new_ramp));
}

void Factory::remove_ramp(ElementID id)
{
    Ramps.remove_by_id(id);
}

NodeCollection<Ramp>::iterator Factory::find_ramp_by_id(ElementID id)
{
    NodeCollection<Ramp>::iterator it;
    for (it = Ramps.begin(); it != Ramps.end(); ++it){
        if(it->get_id() == id)
            return it;
    }
    //Pętla powinna znaleźć odpowiednii element
    assert(false);
    return Ramps.end();
}

NodeCollection<Ramp>::const_iterator Factory::find_ramp_by_id(ElementID id) const
{
    NodeCollection<Ramp>::const_iterator it;
    for (it = Ramps.cbegin(); it != Ramps.cend(); ++it){
        if(it->get_id() == id)
            return it;
    }
    //Pętla powinna znaleźć odpowiednii element
    assert(false);
    return Ramps.cend();
}

NodeCollection<Ramp>::const_iterator Factory::ramp_cbegin() const
{
    return  Ramps.cbegin();
}

NodeCollection<Ramp>::const_iterator Factory::ramp_cend() const
{
    return Ramps.cend();
}

void Factory::add_worker(Worker && new_worker)
{
    Workers.add_node(std::move(new_worker));
}

void Factory::remove_worker(ElementID id)
{
    remove_receiver(Workers,id);
    remove_receiver(Ramps,id);

    Workers.remove_by_id(id);
}

NodeCollection<Worker>::iterator Factory::find_worker_by_id(ElementID id)
{
    NodeCollection<Worker>::iterator it;
    for (it = Workers.begin(); it != Workers.end(); ++it){
        if( it->get_id() == id )
            return it;
    }
    //Pętla powinna znaleźć odpowiednii element
    assert(false);
    return Workers.end();
}

NodeCollection<Worker>::const_iterator Factory::find_worker_by_id(ElementID id) const
{
    NodeCollection<Worker>::const_iterator it;
    for (it = Workers.cbegin(); it != Workers.cend(); ++it){
        if( it->get_id() == id )
            return it;
    }
    //Pętla powinna znaleźć odpowiednii element
    assert(false);
    return Workers.cend();
}

NodeCollection<Worker>::const_iterator Factory::worker_cbegin() const
{
    return Workers.cbegin();
}

NodeCollection<Worker>::const_iterator Factory::worker_cend() const
{
    return Workers.cend();
}

void Factory::add_storehouse(Storehouse && new_Storehouse)
{
    Storehouses.add_node(std::move(new_Storehouse));
}

void Factory::remove_storehouse(ElementID id)
{
    remove_receiver(Workers,id);

    Storehouses.remove_by_id(id);
}

NodeCollection<Storehouse>::iterator Factory::find_storehouse_by_id(ElementID id)
{
    NodeCollection<Storehouse>::iterator it;
    for (it = Storehouses.begin(); it != Storehouses.end(); ++it){
        if( it->get_id() == id )
            return it;
    }
    //Pętla powinna znaleźć odpowiednii element
    assert(false);
    return Storehouses.end();
}

NodeCollection<Storehouse>::const_iterator Factory::find_storehouse_by_id(ElementID id) const
{
    NodeCollection<Storehouse>::const_iterator it;
    for (it = Storehouses.cbegin(); it != Storehouses.cend(); ++it){
        if( it->get_id() == id )
            return it;
    }
    //Pętla powinna znaleźć odpowiednii element
    assert(false);
    return Storehouses.cend();
}

NodeCollection<Storehouse>::const_iterator Factory::storehouse_cbegin() const
{
    return Storehouses.cbegin();
}

NodeCollection<Storehouse>::const_iterator Factory::storehouse_cend() const
{
    return Storehouses.cend();
}

bool Factory::is_consistent() const
{
    std::map<const PackageSender *, NodeColor> dictionary;
    // Zmiana stanu wszystkich Ramp i pracowników na nieodwiedzonych
    for(auto &ramp:Ramps)
    {
        auto* PSend_ptr = (PackageSender *) &ramp;
        dictionary[ PSend_ptr ] = NodeColor::UNVISITED;
    }
    for(auto &worker:Workers)
    {
        auto* PSend_ptr = (PackageSender *) &worker;
        dictionary[ PSend_ptr ] = NodeColor::UNVISITED;
    }

    for(auto &ramp:Ramps)
    {
        try{
            has_reachable_storehouse(&ramp,dictionary);
        } catch (std::logic_error &) {
            return false;
        }
    }
    return true;
}

bool Factory::has_reachable_storehouse(const PackageSender *sender,
                                       std::map<const PackageSender *,
                                       NodeColor> &node_colors) const{

    if(node_colors[sender] == NodeColor::VERIFIED)
        return true;
    node_colors[sender] =NodeColor::VISITED;
    if(sender->receiver_preferences_.get_preferences().empty())
    {
        // Wyrzucenie wyjątku
        throw std::logic_error("Element nie ma odbiorcow");
    }
    bool sender_have_reciver = false;

    for(auto &reciver_p : sender->receiver_preferences_.get_preferences())
    {
        if(reciver_p.first->get_receiver_type() == ReceiverType::STOREHOUSE)
            sender_have_reciver = true;
        else if(reciver_p.first->get_receiver_type() == ReceiverType::WORKER)
        {
            // Konwersja reciver na sender ( bo wiadomo, że mamy do czynienia z Worker):
            IPackageReceiver* receiver_ptr = reciver_p.first;
            auto worker_ptr = dynamic_cast<Worker*>(receiver_ptr);
            auto sendrecv_ptr = dynamic_cast<PackageSender*>(worker_ptr);

            if(sendrecv_ptr == sender)
            {
                continue; // Przejście do kolejnego odbiorcy
            }
            sender_have_reciver = true;
            if(node_colors[sendrecv_ptr] == NodeColor::UNVISITED)
                has_reachable_storehouse(sendrecv_ptr,node_colors);
        }
    }
    node_colors[sender] = NodeColor::VERIFIED;
    if(sender_have_reciver)
        return true;
    else
        // Wyrzucenie wyjątku
        throw std::logic_error("Element nie ma prawidłowych odbiorcow");
}


void Factory::do_deliveries(Time t) {
    for(auto it = Ramps.begin(); it != Ramps.end(); it++){
        it->deliver_goods(t);
    }
}

void Factory::do_package_passing() {
    for(auto it = Ramps.begin(); it != Ramps.end(); it++){
        it->send_package();
    }
    for(auto it = Workers.begin(); it != Workers.end(); it++){
        it->send_package();
    }
}

void Factory::do_work(Time t) {
    for(auto it = Workers.begin(); it != Workers.end(); it++){
        it->do_work(t);
    }
}

/// Wczytywanie i zapis stanu fabryki

Factory load_factory_structure(std::istream& is)
{
    //std::unique_ptr<Factory> factory = std::make_unique<Factory>();
    Factory factory;

    std::string line;

    while (std::getline(is, line)) {
        if(line.empty() or line.front() == ';')
        {
            continue;
        }
        ParsedLineData new_el = parse_line(line);

        if(new_el.element_type == ElementType::RAMP)
        {
            int id = std::stoi( new_el.parameters.find("id")->second );
            int delivery_interval = std::stoi( new_el.parameters.find("delivery-interval")->second );

            factory.add_ramp(Ramp(id,delivery_interval));
        } else if(new_el.element_type == ElementType::WORKER){
            int id = std::stoi( new_el.parameters.find("id")->second );
            int processing_time = std::stoi( new_el.parameters.find("processing-time")->second );

            PackageQueueType queue_type;
            if(new_el.parameters.find("queue-type")->second == "LIFO")
                queue_type = PackageQueueType::LIFO;
            else if(new_el.parameters.find("queue-type")->second == "FIFO")
                queue_type = PackageQueueType::FIFO;
            else
                throw std::logic_error("Nie znaleziono właściwego typu kolejki");

            factory.add_worker(Worker(id,processing_time,std::make_unique<PackageQueue>(queue_type)));
        } else if(new_el.element_type == ElementType::STOREHOUSE) {
            int id = std::stoi(new_el.parameters.find("id")->second);
            factory.add_storehouse(Storehouse(id));
        } else if(new_el.element_type == ElementType::LINK)
        {
            ElementType src_type;
            ElementType dest_type;

            ElementID src_id;
            ElementID dest_id;

            std::string src_str;
            std::string dest_str;

            src_str = new_el.parameters["src"];
            dest_str = new_el.parameters["dest"];

            std::size_t pause_pos_s = src_str.find('-');
            std::string src_type_str = src_str.substr(0,pause_pos_s);
            src_type = get_el_type_small(src_type_str);
            src_id = std::stoi( src_str.substr(pause_pos_s +1 ) );

            std::size_t pause_pos_d = dest_str.find('-');
            std::string dest_type_str = dest_str.substr(0,pause_pos_d);
            dest_type = get_el_type_small(dest_type_str);
            dest_id = std::stoi(dest_str.substr(pause_pos_d + 1));

            if(src_type == ElementType::RAMP)
            {
                if(dest_type == ElementType::WORKER)
                {
                    factory.find_ramp_by_id(src_id)->receiver_preferences_.add_receiver(&(*(factory.find_worker_by_id(dest_id))));
                }else if(dest_type == ElementType::STOREHOUSE)
                {
                    factory.find_ramp_by_id(src_id)->receiver_preferences_.add_receiver(&(*(factory.find_storehouse_by_id(dest_id))));
                }else
                {
                    throw std::logic_error("Nieprawidłowy typ ElementType dla dest");
                }

            }else if(src_type == ElementType::WORKER)
            {
                if(dest_type == ElementType::WORKER)
                {
                    factory.find_worker_by_id(src_id)->receiver_preferences_.add_receiver(&(*(factory.find_worker_by_id(dest_id))));
                }else if(dest_type == ElementType::STOREHOUSE)
                {
                    factory.find_worker_by_id(src_id)->receiver_preferences_.add_receiver(&(*(factory.find_storehouse_by_id(dest_id))));
                }else
                {
                    throw std::logic_error("Nieprawidłowy typ ElementType dla dest");
                }
            }else
            {
                throw std::logic_error("Nieprawidłowy typ ElementType dla src");
            }

        }
    }
    return factory;
}

ParsedLineData parse_line(std::string& line){
    std::vector<std::string> tokens;
    std::string token;

    std::istringstream token_stream(line);
    char delimiter = ' ';

    while (std::getline(token_stream, token, delimiter)) {
        tokens.push_back(token);
    }

    std::map<std::string ,std::string> parameters;

    for(auto it = tokens.begin() + 1;it != tokens.end(); it++ )
    {
        // Podział string-a na dwie części
        char equal = '=';
        std::string value;
        std::vector<std::string> value_list;
        std::istringstream value_stream(*it);
        while (std::getline(value_stream , value, equal)) {
            value_list.push_back(value);
        }
        parameters[value_list[0]] = value_list[1];
    }
    ParsedLineData new_line;

    new_line.parameters = parameters;

    new_line.element_type = get_El_type(tokens[0]);

    return new_line;
}

ElementType get_El_type(std::string& str)
{
    if(str == "LOADING_RAMP")
        return  ElementType::RAMP;
    else if(str == "WORKER")
        return ElementType::WORKER;
    else if(str == "STOREHOUSE")
        return ElementType::STOREHOUSE;
    else if(str == "LINK")
        return ElementType::LINK;
    else
        throw std::logic_error("Niedopasowano typu węzła lub połączenia");
}

ElementType get_el_type_small(std::string& str)
{
    if(str == "ramp")
        return  ElementType::RAMP;
    else if(str == "worker")
        return ElementType::WORKER;
    else if(str == "store")
        return ElementType::STOREHOUSE;
    else
        throw std::logic_error("Niedopasowano typu węzła lub połączenia");
}

void save_factory_structure(Factory& factory, std::ostream& os)
{
    os<<"\n";
    os<<"; == LOADING RAMPS ==";
    os<<"\n";

    std::list<NodeCollection<Ramp>::const_iterator > Ramp_c_its;

    for(auto it_r = factory.ramp_cbegin();it_r != factory.ramp_cend(); it_r++)
    {
        Ramp_c_its.push_back(it_r);
    }

    Ramp_c_its.sort([](auto& a,auto& b){return a->get_id() < b->get_id();});

    for(auto& c_it:Ramp_c_its )
    {
        os<<"LOADING_RAMP id=";
        os<<std::to_string(c_it->get_id());
        os<<" delivery-interval=";
        os<<std::to_string(c_it->get_delivery_interval());
        os<<"\n";

    }

    os<<"\n";


    os<<"; == WORKERS ==";
    os<<"\n";

    std::list<NodeCollection<Worker>::const_iterator > Worker_c_its;

    for(auto it_w = factory.worker_cbegin();it_w != factory.worker_cend(); it_w++)
    {
        Worker_c_its.push_back(it_w);
    }

    Worker_c_its.sort([](auto& a,auto& b){return a->get_id() < b->get_id();});

    for(auto& c_it:Worker_c_its ) {
        os << "WORKER id=";
        os << std::to_string(c_it->get_id());
        os << " processing-time=";
        os << std::to_string(c_it->get_processing_duration());
        os << " queue-type=";

        if (c_it->get_queue()->get_queue_type() == PackageQueueType::LIFO) {
            os << "LIFO";
        } else if (c_it->get_queue()->get_queue_type() == PackageQueueType::FIFO) {
            os << "FIFO";
        } else {
            throw std::logic_error("Nie znaleziono odpowiedniego typu kolejki");
        }
        os << "\n";

    }
    os<<"\n";
    os<<"; == STOREHOUSES ==";
    os<<"\n";

    std::list<NodeCollection<Storehouse>::const_iterator > Store_c_its;

    for(auto it_s = factory.storehouse_cbegin();it_s != factory.storehouse_cend(); it_s++)
    {
        Store_c_its.push_back(it_s);
    }

    Store_c_its.sort([](auto& a,auto& b){return a->get_id() < b->get_id();});

    for(auto& c_it:Store_c_its )
    {
        os<<"STOREHOUSE id=";
        os<<std::to_string(c_it->get_id());
        os<<"\n";
    }

    os<<"\n";
    os<<"; == LINKS ==";
    os<<"\n";


    for(auto it_r = factory.ramp_cbegin();it_r != factory.ramp_cend(); it_r++) {

        for(auto it_2 : it_r->receiver_preferences_.Reciver_list)
        {
            os << "LINK src=ramp-";
            os << std::to_string(it_r->get_id());
            if(it_2.first->get_receiver_type()   == ReceiverType::STOREHOUSE)
                os << " dest=store-";
            else if(it_2.first->get_receiver_type()   == ReceiverType::WORKER)
                os << " dest=worker-";
            else
                throw std::logic_error("Nie znaleziono odpowiedniego typu odbiorcy");
            os<<std::to_string(it_2.first->get_id());
            os<<"\n";
        }
        os<<"\n";
    }

    for(auto it_w = factory.worker_cbegin();it_w != factory.worker_cend(); it_w++) {

        for(auto it_2 : it_w->receiver_preferences_.Reciver_list)
        {
            os << "LINK src=worker-";
            std::string id = std::to_string(it_w->get_id());
            os << id;
            if(it_2.first->get_receiver_type()        == ReceiverType::STOREHOUSE)
                os << " dest=store-";
            else if(it_2.first->get_receiver_type()   == ReceiverType::WORKER)
                os << " dest=worker-";
            else
                throw std::logic_error("Nie znaleziono odpowiedniego typu odbiorcy");
            os<<std::to_string(it_2.first->get_id());
            os<<"\n";
        }
        os<<"\n";
    }


}










// 35: Rafa (401991) Szota(401281)  Lenarczyk(402763)