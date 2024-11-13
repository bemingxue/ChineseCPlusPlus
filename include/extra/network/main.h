
#ifndef _BE_NETWORK_H_
#define _BE_NETWORK_H_

#if __has_include(<boost/asio.hpp>)
#include <boost/asio.hpp>
#else
#error "Boost ASIO library not found. Please install it first."
#error "没有找到 Boost.Asio 库，请先安装并配置到当前项目中。"
#endif

#include "../../main.h"

#include "./basic.h"

#include "./strhttp.h"

#endif
