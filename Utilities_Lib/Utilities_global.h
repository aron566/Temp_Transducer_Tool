/**
 *  @file Utilities_global.h
 *
 *  @date 2021-05-28
 *
 *  @author aron566
 *
 *  @brief None
 *
 *  @version V1.0
 */
#ifndef UTILITIES_GLOBAL_H
#define UTILITIES_GLOBAL_H
/** Includes -----------------------------------------------------------------*/
#include <stdint.h> /**< need definition of uint8_t */
#include <stddef.h> /**< need definition of NULL    */
#include <stdbool.h>/**< need definition of BOOL    */
#include <stdio.h>  /**< if need printf             */
#include <stdlib.h>
#include <string.h>
/** Private includes ---------------------------------------------------------*/
#include <QtCore/qglobal.h>
#include <QObject>
/** Private defines ----------------------------------------------------------*/

/** Exported typedefines -----------------------------------------------------*/

/** Exported constants -------------------------------------------------------*/

/** Exported macros-----------------------------------------------------------*/
/** Exported variables -------------------------------------------------------*/
/** Exported functions prototypes --------------------------------------------*/

#if defined(UTILITIES_LIBRARY)
#  define UTILITIES_EXPORT Q_DECL_EXPORT
#else
#  define UTILITIES_EXPORT Q_DECL_IMPORT
#endif

#endif // UTILITIES_GLOBAL_H
/******************************** End of file *********************************/





