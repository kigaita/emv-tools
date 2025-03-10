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

#ifndef EMV_PKI_PRIV_H
#define EMV_PKI_PRIV_H

#include "openemv/crypto.h"
#include "openemv/emv_pk.h"
#include "openemv/tlv.h"

#include <stddef.h>

struct emv_pk *emv_pki_make_ca(const struct crypto_pk *cp,
		const unsigned char *rid, unsigned char index,
		unsigned int expire, enum crypto_algo_hash hash_algo);
struct tlvdb *emv_pki_sign_issuer_cert(const struct crypto_pk *cp, struct emv_pk *issuer_pk);
struct tlvdb *emv_pki_sign_icc_cert(const struct crypto_pk *cp, struct emv_pk *icc_pk, const unsigned char *sda_data, size_t sda_data_len);
struct tlvdb *emv_pki_sign_icc_pe_cert(const struct crypto_pk *cp, struct emv_pk *icc_pe_pk);

struct tlvdb *emv_pki_sign_dac(const struct crypto_pk *cp, const unsigned char *dac, const unsigned char *sda_data, size_t sda_data_len);
struct tlvdb *emv_pki_sign_idn(const struct crypto_pk *cp, const unsigned char *idn, size_t idn_len, const unsigned char *dyn_data, size_t dyn_data_len);

#endif
