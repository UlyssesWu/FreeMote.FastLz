# FreeMote.FastLz
[![MyGet](https://buildstats.info/myget/monarchsolutions/FreeMote.FastLz)](https://www.myget.org/feed/monarchsolutions/package/nuget/FreeMote.FastLz)

.NET binding library for [FastLZ](https://github.com/ariya/FastLZ).

## Benchmark
**FreeMote.FastLz** (Native binding) vs [**DotFastLZ**](https://github.com/ikpil/DotFastLZ) (Managed implementation, v2023.10.5)

Input: a 64MB PNG image

```
BenchmarkDotNet v0.13.10, Windows 11 (10.0.22631.2715/23H2/2023Update/SunValley3)
11th Gen Intel Core i7-11800H 2.30GHz, 1 CPU, 16 logical and 8 physical cores
  [Host]     : .NET Framework 4.8.1 (4.8.9181.0), X64 RyuJIT VectorSize=256
  DefaultJob : .NET Framework 4.8.1 (4.8.9181.0), X64 RyuJIT VectorSize=256
```

| Method             | Mean      | Error    | StdDev   |
|------------------- |----------:|---------:|---------:|
| CompressNativeLv1  | 106.98 ms | 0.503 ms | 0.392 ms |
| CompressManagedLv1 | 207.63 ms | 1.042 ms | 0.923 ms |
| CompressNativeLv2  | 127.98 ms | 0.414 ms | 0.388 ms |
| CompressManagedLv2 | 221.41 ms | 3.040 ms | 2.843 ms |
| DecompressNative   |  82.52 ms | 0.459 ms | 0.429 ms |
| DecompressManaged  | 105.83 ms | 1.046 ms | 0.927 ms |


## License
MIT

---

by Ulysses (wdwxy12345@gmail.com)
