
#ifndef _BE_NETWORK_H_
#define _BE_NETWORK_H_

#if __has_include(<boost/asio.hpp>)
#include <boost/asio.hpp>
#else
#error "Boost ASIO library not found. Please install it first."
#error "û���ҵ� Boost.Asio �⣬���Ȱ�װ�����õ���ǰ��Ŀ�С�"
#endif

#include "../../main.h"

#include "./basic.h"

#include "./strhttp.h"

#endif
