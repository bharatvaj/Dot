#include <Dot/Writer.hpp>
#include <Dot/Dot.hpp>
#include <comm.h>
#include <clog/clog.h>

static const char *TAG = "Writer";

dot::Writer::Writer()
{
}

dot::Writer::Writer(Dot *dot)
{
    this->dot = dot;
}

dot::Writer &dot::Writer::write(std::string message)
{
    //comm_write_text(dot->getSocket(), message.c_str(), message.en);

      char *temp = strdup(message.c_str());
      size_t wrote = ::send(dot->getSocket(), temp, message.length(), 0); //TODO use libcomm to support atomic functions
      if(wrote < 1){
        log_err(TAG, "Opeation failed");
        fireEvent(DotOperationEvent::FAILED, *dot);
      } else {
        fireEvent(DotOperationEvent::SUCCESS, *dot);
      }
    return *this;
}

dot::Writer &dot::Writer::write(std::string message){
    //add to queue and let runner decide whether to run or not
    //DotState dotState;
    //writeFunc(dotState);
    Writer &writer = *(new Writer(this));
    return writer;
}
