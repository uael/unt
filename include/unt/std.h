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

/*!@file unt/std.h
 * @author uael
 */
#ifndef __UNT_STD_H
# define __UNT_STD_H

#include <ucc.h>

#ifdef __cplusplus
# include <cstdlib>
# include <cstdarg>
# include <cstddef>
# include <cstdint>
# include <cstdio>
#else
# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
#endif

#if __has_feature(stdalign_h)
# ifdef __cplusplus
#   include <cstdalign>
# else
#   include <stdalign.h>
# endif
#endif

#if __has_feature(stdatomic_h)
# ifdef __cplusplus
#   include <cstdatomic>
# else
#   include <stdatomic.h>
# endif
#endif

#ifdef OS_UNIX
# include <unistd.h>
#endif

#ifdef OS_WIN
# define NOCRYPT
# include <windows.h>
# undef NOCRYPT
# include <winnt.h>
# include <windef.h>
#endif

#endif /* !__UNT_STD_H */
