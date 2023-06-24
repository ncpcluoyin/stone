#define types
#type enum

#special types
typeString = -1

typeInt8 = 0
typeInt16 = 1
typeInt32 = 2
typeInt64 = 3
typeInt128 = 4

typeUInt8 = 5
typeUInt16 = 6
typeUInt32 = 7
typeUInt64 = 8
typeUInt128 = 9

typeChar = 10

typeFloat32 = 11
typeFloat64 = 12

CString = "char*"

#must include stdin-gcc.h
CInt8 = "int8_t"
CInt16 = "int16_t"
CInt32 = "int32_t"
CInt64 = "int64_t"
CInt128 = "__int128"#gcc

CUInt8 = "uint8_t"
CUInt16 = "uint16_t"
CUInt32 = "uint32_t"
CUInt64 = "uint64_t"
CUInt128 = "__uint128"#gcc

CChar = "char"

CFloat32 = "float"
CFloat64 = "double"

def basicTypeConvertToCType(Type:int):
    result = str()
    #int
    if Type == typeInt8:
        result = CInt8
    if Type == typeInt16:
        result = CInt16
    if Type == typeInt32:
        result = CInt32
    if Type == typeInt64:
        result = CInt64
    if Type == typeInt128:
        result = CInt128
    #unit
    if Type == typeUInt8:
        result = CUInt8
    if Type == typeUInt16:
        result = CUInt16
    if Type == typeUInt32:
        result = CUInt32
    if Type == typeUInt64:
        result = CUInt64
    if Type == typeUInt128:
        result = CUInt128
    #char
    if Type == typeChar:
        result = CChar
    #float
    if Type == typeFloat32:
        result = CFloat32
    if Type == typeFloat64:
        result = CFloat64
    return result