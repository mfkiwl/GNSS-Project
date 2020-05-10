/*
 * Generated by asn1c-0.9.22 (http://lionet.info/asn1c)
 * From ASN.1 module "RRLP-Components"
 * 	found in "../rrlp-components.asn"
 */

#ifndef _ReferenceFrame_H_
#define _ReferenceFrame_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /* ReferenceFrame */
    typedef struct ReferenceFrame
    {
        long referenceFN;
        long *referenceFNMSB /* OPTIONAL */;

        /* Context for parsing across buffer boundaries */
        asn_struct_ctx_t _asn_ctx;
    } ReferenceFrame_t;

    /* Implementation */
    extern asn_TYPE_descriptor_t asn_DEF_ReferenceFrame;

#ifdef __cplusplus
}
#endif

#endif /* _ReferenceFrame_H_ */
#include <asn_internal.h>