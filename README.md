Project Specifications:
![image](https://github.com/PandaBunBuns/SOLIS_Deep-Dive/assets/87511092/1bf97d95-62ca-4c44-b171-9c3361c7951f)


1. Comparative execution time as well as analysis of the performance of different kernels (how many times faster, why is it faster, overheads in calling the kernel, etc.)

   It should be noted that even though the code of the SIMD ASM function is working, the output is incorrect. The output fails to compute for the first 3 Y values and starts with the 4th, which is 49. This causes the error count to be equal to the number of elements in the Y vector. Even with this error, it is assumed that the average time is correct.

   |   Kernel  |    2^20   |    2^24    |     2^29     |
   | --------- | --------- | ---------- | ------------ |
   | C Program | 4033.33us | 64466.67us | 2205566.67us |
   | --------- | --------- | ---------- | ------------ |
   |    ASM    | 2200.00us | 32033.33us | 1194666.67us |
   | --------- | --------- | ---------- | ------------ |
   |    SIMD   | 333.33us  | 15100.00us | 680500.00us  |

   When comparing ASM and C Program kernels, it can be seen that ASM around 2x faster in all of the Array Sizes. Specifically 1.83x, 2.01x, 3.24x faster for Array Sizes 2^20, 2^24, and 2^29, respectively. This shows that ASM is significantly more efficient than C Program and more so if the Array Size is large.

   When comparing SIMD and C Program kernels, it is also demonstrated that SIMD is significantly faster than the latter in all Array Sizes. Specifically 12.10x, 4.27x, and 3.24x faster for Array Sizes 2^20, 2^24, and 2^30, respectively. There is a significant decrease in average time which means it is more efficient. Though as the Array Size increases, the factor in which the average time of SIMD is faster decreases. This suggests that the significance in time advantage for SIMD to ASM will also decrease. This could mean that there is no significant advantage in kernel if the Array Size is large enough.

3. 2^20 Results
   
   ![image](https://github.com/PandaBunBuns/SOLIS_Deep-Dive/assets/87511092/1f774115-7792-496d-b8e1-6db1b170fbc1)

4. 2^24 Results
   
   ![image](https://github.com/PandaBunBuns/SOLIS_Deep-Dive/assets/87511092/116cafb3-130c-40cd-8cfc-3c13f10a91b2)

5. 2^29 Results
   
   ![image](https://github.com/PandaBunBuns/SOLIS_Deep-Dive/assets/87511092/f7cd9503-112a-4ef9-ae4b-5e6246704292)

