//#include "gtest/gtest.h"
//
//#include "nodes.hpp"
//#include "types.hpp"
//#include "storage_types.hpp"
//#include "helpers.hpp"
//#include "package.hpp"
//
//TEST(RampTest, deliverGoods){
//    Ramp r1(1, 2);
//    Ramp r2(2, 1);
//
//    auto recv = std::make_unique<Storehouse>(23);
//    r1.receiver_preferences_.add_receiver(recv.get());
//
//    r1.deliver_goods(1);
//    r1.send_package();
//    r1.deliver_goods(2);
//    r2.deliver_goods(2);
//
//    ASSERT_FALSE(r1.get_sending_buffer().has_value());
//    ASSERT_TRUE(r2.get_sending_buffer().has_value());
//}
//
//TEST(Storehouse, all_go_to_end)
//{
//    // Tesy autorstwa Wojciech Rafa
//    Ramp r1(1, 2);
//    Ramp r2(2, 1);
//
//    // Kolejki dla pracowników:
//    auto q1 = std::make_unique<PackageQueue>(PackageQueueType::LIFO);
//    auto q2 = std::make_unique<PackageQueue>(PackageQueueType::FIFO);
//
//    Worker w1(1,1,std::move(q1));
//    Worker w2(2,2,std::move(q2));
//
//    auto q3 = std::make_unique<PackageQueue>(PackageQueueType::LIFO);
//    auto q4 = std::make_unique<PackageQueue>(PackageQueueType::FIFO);
//
//    Storehouse s1(3,std::move(q3));
//    Storehouse s2(4,std::move(q4));
//
//    r1.receiver_preferences_.add_receiver(&w1);
//    r2.receiver_preferences_.add_receiver(&w2);
//
//    w1.receiver_preferences_.add_receiver(&s1);
//    w2.receiver_preferences_.add_receiver(&s2);
//
//    r1.deliver_goods(1);
//    r2.deliver_goods(1);
//
//    r1.deliver_goods(2);
//    r2.deliver_goods(2);
//
//    ASSERT_TRUE(r1.get_sending_buffer().has_value());
//    ASSERT_TRUE(r2.get_sending_buffer().has_value());
//
//    std::list<PackageSender*> sender_list;
//
//    sender_list.push_back(&r1);
//    sender_list.push_back(&r2);
//
//    sender_list.push_back(&w1);
//    sender_list.push_back(&w2);
//
//    for(int i=0;i<20;i++)
//    {
//        for(auto sender_ptr:sender_list)
//        {
//            sender_ptr->send_package();
//        }
//    }
//    ASSERT_EQ(false, r1.get_sending_buffer().has_value());
//    ASSERT_EQ(false, r2.get_sending_buffer().has_value());
//    ASSERT_EQ(false, w1.get_sending_buffer().has_value());
//    ASSERT_EQ(false, w2.get_sending_buffer().has_value());
//}


