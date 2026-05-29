//#include <iostream>
#include "gmock/gmock.h"
#include "sms_sender.cpp"

class TestableSmsSender : public SmsSender
{
public:
    MOCK_METHOD(void, send, (Schedule*), (override));

//    void send(Schedule* schedule) override
//    {
//        std::cout << "테스트용 SmsSender class의 send메서드 실행됨\n";
//        sendMethodIsCalled = true;
//    }
//
//    bool isSendMethodIsCalled()
//    {
//        return sendMethodIsCalled;
//    }
//
//private:
//    bool sendMethodIsCalled;
};