#include "log.hpp"
#include <cassert>
#include "log.hpp"

namespace logging
{		

void file_log_policy::open_out_stream(const std::string& name)
{
    out_stream.open( name.c_str(), std::ios_base::binary|std::ios_base::out );
    assert( out_stream.is_open() == true );
    out_stream.precision( 20 );
}

void file_log_policy::close_out_stream()
{
    if( out_stream )
    {
        out_stream.close();
    }
}

void file_log_policy::write(const std::string& msg)
{
    out_stream<<msg<<std::endl<<std::flush;
}
}

