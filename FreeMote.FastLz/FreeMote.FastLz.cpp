#include "fastlz.h"
#include "FreeMote.FastLz.h"

Int32 calcBufferSize(Int32 inputSize)
{
	return Math::Max(66, static_cast<int>(1.06 * inputSize));
}

array<unsigned char>^ FreeMote::FastLz::FastLzNative::Compress(array<unsigned char>^ input, FastLzLevel level)
{
	array<Byte>^ buf = gcnew array<Byte>(calcBufferSize(input->Length));
	const pin_ptr<unsigned char> bufPtr = &buf[0];
	const pin_ptr<const unsigned char> inputPtr = &input[0];
	const int result = fastlz_compress_level(static_cast<int>(level), inputPtr, input->Length, bufPtr);
	if (result == 0)
	{
		return nullptr;
	}
	if (result == buf->Length)
	{
		return buf;
	}
	array<Byte>^ outBuf = gcnew array<Byte>(result);
	Array::Copy(buf, 0, outBuf, 0, result);
	return outBuf;
}

array<unsigned char>^ FreeMote::FastLz::FastLzNative::Compress(array<unsigned char>^ input)
{
	if (input->Length < 65536)
	{
		return Compress(input, FastLzLevel::Level1);
	}
	return Compress(input, FastLzLevel::Level2);
}

array<unsigned char>^ FreeMote::FastLz::FastLzNative::Decompress(array<unsigned char>^ input, int maxout, FastLzLevel level)
{
	if (maxout < input->Length)
	{
		maxout = calcBufferSize(input->Length);
	}

	array<Byte>^ buf = gcnew array<Byte>(maxout);
	const pin_ptr<unsigned char> bufPtr = &buf[0];
	const pin_ptr<const unsigned char> inputPtr = &input[0];
	int result = 0;
	if (level == FastLzLevel::Level1)
	{
		result = fastlz1_decompress(inputPtr, input->Length, bufPtr, maxout);
	}
	else
	{
		result = fastlz2_decompress(inputPtr, input->Length, bufPtr, maxout);
	}
	
	if (result == 0)
	{
		return nullptr;
	}
	if (result == buf->Length)
	{
		return buf;
	}
	array<Byte>^ outBuf = gcnew array<Byte>(result);
	Array::Copy(buf, 0, outBuf, 0, result);
	return outBuf;
}

array<unsigned char>^ FreeMote::FastLz::FastLzNative::Decompress(array<unsigned char>^ input, int maxout)
{
	if (maxout < input->Length)
	{
		maxout = calcBufferSize(input->Length);
	}

	array<Byte>^ buf = gcnew array<Byte>(maxout);
	const pin_ptr<unsigned char> bufPtr = &buf[0];
	const pin_ptr<const unsigned char> inputPtr = &input[0];
	const int result = fastlz_decompress(inputPtr, input->Length, bufPtr, maxout);

	if (result == 0)
	{
		return nullptr;
	}
	if (result == buf->Length)
	{
		return buf;
	}
	array<Byte>^ outBuf = gcnew array<Byte>(result);
	Array::Copy(buf, 0, outBuf, 0, result);
	return outBuf;
}
