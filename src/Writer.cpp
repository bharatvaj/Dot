#include <Dot/Writer.hpp>

dot::Writer::Writer()
{
}

dot::Writer::Writer(Dot *dot)
{
    this->dot = dot;
}

dot::Writer &dot::Writer::write(std::string message)
{
    //int bytes_written = comm_write(sockfd, message);
    //if(bytes_written < 0){
    //fireEvent(DotOperationEvent::FAILED, *dot, *this);
    //} else {
    //fireEvent(DotOperationEvent::SUCCESS, *dot, *this );
    //}
    return *this;
}
