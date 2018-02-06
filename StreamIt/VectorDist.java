import java.io.Serializable;
import streamit.library.*;
import streamit.library.io.*;
import streamit.misc.StreamItRandom;
class Complex extends Structure implements Serializable {
  float real;
  float imag;
}
class float2 extends Structure implements Serializable {
  float x;
  float y;
}
class float3 extends Structure implements Serializable {
  float x;
  float y;
  float z;
}
class float4 extends Structure implements Serializable {
  float x;
  float y;
  float z;
  float w;
}
class StreamItVectorLib {
  public static native float2 add2(float2 a, float2 b);
  public static native float3 add3(float3 a, float3 b);
  public static native float4 add4(float4 a, float4 b);
  public static native float2 sub2(float2 a, float2 b);
  public static native float3 sub3(float3 a, float3 b);
  public static native float4 sub4(float4 a, float4 b);
  public static native float2 mul2(float2 a, float2 b);
  public static native float3 mul3(float3 a, float3 b);
  public static native float4 mul4(float4 a, float4 b);
  public static native float2 div2(float2 a, float2 b);
  public static native float3 div3(float3 a, float3 b);
  public static native float4 div4(float4 a, float4 b);
  public static native float2 addScalar2(float2 a, float b);
  public static native float3 addScalar3(float3 a, float b);
  public static native float4 addScalar4(float4 a, float b);
  public static native float2 subScalar2(float2 a, float b);
  public static native float3 subScalar3(float3 a, float b);
  public static native float4 subScalar4(float4 a, float b);
  public static native float2 scale2(float2 a, float b);
  public static native float3 scale3(float3 a, float b);
  public static native float4 scale4(float4 a, float b);
  public static native float2 scaleInv2(float2 a, float b);
  public static native float3 scaleInv3(float3 a, float b);
  public static native float4 scaleInv4(float4 a, float b);
  public static native float sqrtDist2(float2 a, float2 b);
  public static native float sqrtDist3(float3 a, float3 b);
  public static native float sqrtDist4(float4 a, float4 b);
  public static native float dot3(float3 a, float3 b);
  public static native float3 cross3(float3 a, float3 b);
  public static native float2 max2(float2 a, float2 b);
  public static native float3 max3(float3 a, float3 b);
  public static native float2 min2(float2 a, float2 b);
  public static native float3 min3(float3 a, float3 b);
  public static native float2 neg2(float2 a);
  public static native float3 neg3(float3 a);
  public static native float4 neg4(float4 a);
  public static native float2 floor2(float2 a);
  public static native float3 floor3(float3 a);
  public static native float4 floor4(float4 a);
  public static native float2 normalize2(float2 a);
  public static native float3 normalize3(float3 a);
  public static native float4 normalize4(float4 a);
  public static native boolean greaterThan3(float3 a, float3 b);
  public static native boolean lessThan3(float3 a, float3 b);
  public static native boolean equals3(float3 a, float3 b);
}
class VSource extends Filter // VectorDist.str:1
{
  public VSource()
  {
    setStateful(true);
  }
  float x; // VectorDist.str:2
  float y; // VectorDist.str:3
  public void work() { // VectorDist.str:8
    x += 3.25f; // VectorDist.str:9
    outputChannel.pushFloat(x); // VectorDist.str:10
    y += 0.42f; // VectorDist.str:11
    outputChannel.pushFloat(y); // VectorDist.str:12
  }
  public void init() { // VectorDist.str:4
    setIOTypes(Void.TYPE, Float.TYPE); // VectorDist.str:1
    addSteadyPhase(0, 0, 2, "work"); // VectorDist.str:8
    x = 0; // VectorDist.str:5
    y = 0; // VectorDist.str:6
  }
}
class Worker extends Filter // VectorDist.str:16
{
  public Worker()
  {
  }
  public void work() { // VectorDist.str:17
    float x = inputChannel.popFloat(); // VectorDist.str:18
    float y = inputChannel.popFloat(); // VectorDist.str:19
    outputChannel.pushFloat(((x - y) * (x - y))); // VectorDist.str:20
  }
  public void init() { // VectorDist.str:16
    setIOTypes(Float.TYPE, Float.TYPE); // VectorDist.str:16
    addSteadyPhase(2, 2, 1, "work"); // VectorDist.str:17
  }
}
class FloatPopper extends Filter // VectorDist.str:31
{
  public FloatPopper()
  {
  }
  public void work() { // VectorDist.str:32
    inputChannel.popFloat(); // VectorDist.str:33
  }
  public void init() { // VectorDist.str:31
    setIOTypes(Float.TYPE, Void.TYPE); // VectorDist.str:31
    addSteadyPhase(1, 1, 0, "work"); // VectorDist.str:32
  }
}
public class VectorDist extends StreamItPipeline // VectorDist.str:37
{
  public void init() { // VectorDist.str:37
    add(new VSource()); // VectorDist.str:38
    add(new Worker()); // VectorDist.str:39
    add(new FloatPopper()); // VectorDist.str:41
  }
}
