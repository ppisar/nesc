/* This file is part of the nesC compiler.

This file is derived from RC and the GNU C Compiler. It is thus
   Copyright (C) 1987, 88, 89, 92-7, 1998 Free Software Foundation, Inc.
   Copyright (C) 2000-2001 The Regents of the University of California.
Changes for nesC are
   Copyright (C) 2002 Intel Corporation

The attached "nesC" software is provided to you under the terms and
conditions of the GNU General Public License Version 2 as published by the
Free Software Foundation.

nesC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with nesC; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA. */

#ifndef C_LEX_H
#define C_LEX_H

#include "config.h"

typedef enum { l_c, l_interface, l_component, l_implementation, l_any } source_language;

typedef struct location
{ 
  const char *filename;
  struct nesc_declaration *container; /* for instantiated code only */
  unsigned long lineno;
  bool in_system_header;
} *location;

extern location last_location, dummy_location, toplevel_location;

location new_location(const char *filename, int lineno);

enum rid
{
  RID_UNUSED,

  RID_INT,
  RID_CHAR,
  RID_FLOAT,
  RID_DOUBLE,
  RID_VOID,

  RID_UNSIGNED,
  RID_SHORT,
  RID_LONG,
  RID_SIGNED,
  RID_INLINE,
  RID_COMPLEX,
  RID_DEFAULT,
  RID_NORACE,

  RID_AUTO,
  RID_STATIC,
  RID_EXTERN,
  RID_REGISTER,
  RID_TYPEDEF,
  RID_COMMAND,
  RID_EVENT,
  RID_TASK,
  RID_ASYNC,

  RID_MAX
};

#define NORID RID_UNUSED

void init_lex(void);
void start_lex(source_language l);
int lex_getc(void);
void lex_ungetc(int c);
void skip_c_comment(void);
void skip_cpp_comment(void);

/**
 * Retrieve the latest code documentation string.  This is used to
 * place the documentation into the appropriate data_declaration.
 **/
void get_latest_docstring(char **short_s, char **long_s, struct location **loc);
char *get_docstring();
void separate_short_docstring(char *str, char **short_s, char **long_s);

location make_location(struct location l);

#endif
