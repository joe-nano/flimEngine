#pragma once
#ifndef ERR_H
#define ERR_H

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \enum	errcode
///
/// \brief	Values that represent errcodes.
////////////////////////////////////////////////////////////////////////////////////////////////////

typedef enum errcode
{
	success,
	failure,
	badptr,
	notfound,
	nullscene,
	no_terrain
} errcode;


#endif ERR_H