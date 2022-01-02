#pragma once
using namespace System;

namespace FreeMote {
	namespace FastLz
	{
		public enum class FastLzLevel : Int32
		{
			Unknown = 0,
			Level1 = 1,
			Level2 = 2
		};

		public ref class FastLzNative
		{
		public:
			static array<Byte>^ Decompress(array<Byte>^ input, Int32 maxout, FastLzLevel level);
			static array<Byte>^ Decompress(array<Byte>^ input, Int32 maxout);
			static array<Byte>^ Compress(array<Byte>^ input);
			static array<Byte>^ Compress(array<Byte>^ input, FastLzLevel level);
		};
	}
}
