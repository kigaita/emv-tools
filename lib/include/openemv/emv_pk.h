/*
 * libopenemv - a library to work with EMV family of smart cards
 * Copyright (C) 2015 Dmitry Eremin-Solenikov
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 */

#ifndef EMV_PK_H
#define EMV_PK_H

#include <stdbool.h>
#include <stddef.h>

struct emv_pk {
	unsigned char rid[5];
	unsigned char index;
	unsigned char serial[3];
	unsigned char pan[10];
	unsigned char hash_algo;
	unsigned char pk_algo;
	unsigned char hash[20];
	unsigned char exp[3];
	size_t elen;
	size_t mlen;
	unsigned char *modulus;
	unsigned int expire;
};

#define EXPIRE(yy, mm, dd)	0x ## yy ## mm ## dd

struct emv_pk *emv_pk_parse_pk(char *buf);
struct emv_pk *emv_pk_new(size_t modlen, size_t explen);
void emv_pk_free(struct emv_pk *pk);
unsigned char *emv_pk_dump_pk(const struct emv_pk *pk);
bool emv_pk_verify(const struct emv_pk *pk);

struct emv_pk *emv_pk_get_ca_pk(const unsigned char *rid, unsigned char idx);
#endif
