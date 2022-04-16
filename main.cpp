// 35: Rafa (401991) Szota(401281)  Lenarczyk(402763)
#include <iostream>
#include <vector>
#include <memory>
#include "storage_types.hpp"
#include "package.hpp"
#include "factory.hpp"

int main()
{
    std::string r1 = "LOADING_RAMP id=1 delivery-interval=3";
    std::string r2 = "LOADING_RAMP id=2 delivery-interval=2";
    std::string w1 = "WORKER id=1 processing-time=2 queue-type=FIFO";
    std::string w2 = "WORKER id=2 processing-time=1 queue-type=LIFO";
    std::string s1 = "STOREHOUSE id=1";
    std::string l1 = "LINK src=ramp-1 dest=worker-1";
    std::string l2 = "LINK src=ramp-2 dest=worker-1";
    std::string l3 = "LINK src=ramp-2 dest=worker-2";
    std::string l4 = "LINK src=worker-1 dest=worker-1";
    std::string l5 = "LINK src=worker-1 dest=worker-2";
    std::string l6 = "LINK src=worker-2 dest=store-1";

    std::set<std::string> input_set = {r1, r2, w1, w2, s1, l1, l2, l3, l4, l5, l6};

    std::vector<std::string> input_lines{
            "; == LOADING RAMPS ==",
            "",
            r2,
            r1,
            "",
            "; == WORKERS ==",
            "",
            w2,
            w1,
            "",
            "; == STOREHOUSES ==",
            "",
            s1,
            "",
            "; == LINKS ==",
            "",
            l2,
            "",
            l1,
            l4,
            "",
            l3,
            l6,
            "",
            l5,
    };

    // ignore empty lines, ignore comments ("; ...")
    // resulting set must be empty

    std::string factoryStructureStr = std::accumulate(input_lines.begin(), input_lines.end(), std::string(""),
                                                      [](std::string accu, std::string line) {
                                                          return accu + line + "\n";
                                                      });

    std::istringstream iss(factoryStructureStr);
    Factory factory;

    factory = load_factory_structure(iss);

    std::ostringstream oss;
    save_factory_structure(factory, oss);

    std::vector<std::string> output_lines;
    //
    std::string structure_str = oss.str();

    iss.str(structure_str);
    iss.clear();
    std::string line;
    while (std::getline(iss, line, '\n')) {
        bool is_blank_line = line.empty() || isblank(line[0]);
        bool is_comment_line = !line.empty() && line[0] == ';';
        if (is_blank_line || is_comment_line) {
            continue;
        }

        output_lines.push_back(line);
    }

    std::cout<<" Wejscie "<<std::endl;
    for(auto& string :input_lines)
    {
        std::cout<<1<<" "<<string<<std::endl;
    }

    std::cout<<" Wyjscie "<<std::endl<<std::endl<<std::endl;
    for(auto& string :output_lines)
    {
        std::cout<<1<<" "<<string<<std::endl;
    }


}
// 35: Rafa (401991) Szota(401281)  Lenarczyk(402763)