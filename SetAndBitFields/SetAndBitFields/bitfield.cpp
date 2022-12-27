#include "bitfield.h"

TBitField::TBitField(size_t _BitLen) {
	bitLen = _BitLen;
	memLen = bitLen / sizeof(elem_type) + (bitLen % sizeof(elem_type));
}

TBitField::TBitField(const TBitField& bf) {
	bitLen = bf.bitLen;
	memLen = bf.memLen;
	pMem = bf.pMem;
	bitsInElem = bf.bitsInElem;
	shiftSize = bf.shiftSize;
}

TBitField::TBitField(TBitField&& bf) {
	bitLen = bf.bitLen;
	memLen = bf.memLen;
	pMem = bf.pMem;
	bitsInElem = bf.bitsInElem;
	shiftSize = bf.shiftSize;
}

TBitField::~TBitField() {
	
}