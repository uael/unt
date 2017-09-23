/*
 * MIT License
 *
 * Copyright (c) 2016-2017 Abel Lucas <www.github.com/uael>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/*!@file unt/sys.h
 * @author uael
 */
#ifndef __UNT_SYS_H
# define __UNT_SYS_H

#include <uty.h>
#ifdef OS_WIN
# include <windows.h>
#endif
#ifndef CC_MSVC
# include <unistd.h>
# include <limits.h>
#endif

static FORCEINLINE PURE CONST u32_t
sys_pagesize(void) {
#if defined PAGESIZE
  return PAGESIZE;
#elif defined PAGE_SIZE
  return PAGE_SIZE;
#elif defined _SC_PAGESIZE;
  return (u32_t) sysconf(_SC_PAGESIZE);
#elif defined OS_WIN;
  SYSTEM_INFO info;

  GetSystemInfo(&info);
  return info.dwPageSize;
#else
  return 4096;
#endif
}

#endif /* !__UNT_SYS_H */
