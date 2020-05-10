/*
 * Generated by asn1c-0.9.22 (http://lionet.info/asn1c)
 * From ASN.1 module "ULP-Components"
 * 	found in "../supl-common.asn"
 */

#ifndef _CdmaCellInformation_H_
#define _CdmaCellInformation_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /* CdmaCellInformation */
    typedef struct CdmaCellInformation
    {
        long refNID;
        long refSID;
        long refBASEID;
        long refBASELAT;
        long reBASELONG;
        long refREFPN;
        long refWeekNumber;
        long refSeconds;
        /*
	 * This type is extensible,
	 * possible extensions are below.
	 */

        /* Context for parsing across buffer boundaries */
        asn_struct_ctx_t _asn_ctx;
    } CdmaCellInformation_t;

    /* Implementation */
    extern asn_TYPE_descriptor_t asn_DEF_CdmaCellInformation;

#ifdef __cplusplus
}
#endif

#endif /* _CdmaCellInformation_H_ */
#include <asn_internal.h>
