/*
 * This file is part of AV Orchid.
 * Copyright (c) 2013, Dmitri R. Kuvshinov <evetro.here@gmail.com>
 * 
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all copies.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */
/**
 * @file   Timer.cpp
 * @brief  Timer.h implementation
 * @author Dmitri Kuvshinov
 */
#include <avo/Timer.h>

//
// Windows targets use high-performance timer
#if defined(WIN32)
//

#define WIN32_LEAN_AND_MEAN // NO*** stuff might have been defined too
#include <Windows.h>

namespace
{
  struct HPT
  {
    long long start;
    double freq;

    HPT()
      : freq (1.0), start (1)
    {
      long long fr = 1;
      QueryPerformanceFrequency (reinterpret_cast <LARGE_INTEGER*> (&fr));
      freq = static_cast <double> (fr);
      QueryPerformanceCounter (reinterpret_cast <LARGE_INTEGER*> (&start));
    }

    double operator()() const
    {
      long long t = 0;
      QueryPerformanceCounter (reinterpret_cast <LARGE_INTEGER*> (&t));
      return static_cast <double> (t - start) / freq;
    }
  } Hpt; // high-performance timer, global static (hidden) object
  // should be thread-safe, it's state is not being changed after creation
}
 
double avo::seconds()
{
  return Hpt();
}

double avo::timer_ticks()
{
  return Hpt.freq;
}

void avo::sleep(double t)
{
  Sleep(static_cast<DWORD>(1000.0 * t));
}

//
// non-Windows Boost-enabled targets may enable use Boost clocks
#elif defined(TIMER_USE_BOOST) // define this macro
// unckecked!

#include <boost/chrono.hpp>
#include <boost/thread/thread.hpp>

double avo::seconds()
{
  boost::chrono::duration<double> d = boost::chrono::high_resolution_clock::now().time_since_epoch();
  return d.count();
}

double avo::timer_ticks()
{
  return 1.0e+9; // pseudoticks, nanoseconds
}

void avo::sleep(double t)
{
  boost::this_thread::sleep_for(boost::chrono::milliseconds(static_cast<int>(1000.0 * t)));
}

//
// or use Chrono from C++11
#elif _MSC_VER >= 1700 || defined(TIMER_USE_STD_CHRONO) // define this macro
//

#include <chrono>
#include <thread>

double avo::seconds()
{
  std::chrono::duration<double> d = std::chrono::high_resolution_clock::now().time_since_epoch();
  return d.count();
}

double avo::timer_ticks()
{
  return 1.0e+9; // pseudoticks, nanoseconds
}

void avo::sleep(double t)
{
  std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(1000.0 * t)));
}


//
// if no Boost but we have OpenMP then use OpenMP time things
#elif defined(_OPENMP)
//
  
#include <omp.h>

double avo::seconds()
{
  return omp_get_wtime();
}

double avo::timer_ticks()
{
  return omp_get_wticks();
}

// simulation, not CPU-friendly (might use lock to try preemptive thread switching)
void avo::sleep(double t)
{
  for (double t1 = seconds() + t; seconds() < t1; )
    continue;
}

//
// if neither Windows nor OpenMP is available, then fallback to std C clock
#else
//

#include <ctime>

double avo::seconds()
{
  return static_cast<double>(std::clock()) / static_cast<double>(CLOCKS_PER_SEC);
}

double avo::timer_ticks()
{
  return CLOCKS_PER_SEC;
}

// simulation, not CPU-friendly
void avo::sleep(double t)
{
  const std::clock_t t1 = std::clock() + static_cast<int>(1000.0 * t);
  while (std::clock() < t1)
    continue;
}

#endif
