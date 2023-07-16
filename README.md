Project Specifications:
![image](https://github.com/PandaBunBuns/SOLIS_Deep-Dive/assets/87511092/1bf97d95-62ca-4c44-b171-9c3361c7951f)


1. Comparative execution time as well as analysis of the performance of different kernels (how many times faster, why is it faster, overheads in calling the kernel, etc.)

   |   Kernel  | 2^20  | 2^24  | 2^29  |
   | --------- | --- | --- | --- |
   | C Program | 301 | 283 |
   | --------- | --- | --- |
   |    ASM    | 301 | 283 |
   | --------- | --- | --- |
   |    SIMD   | 301 | 283 |

3. 2^20 Results
   
   ![image](https://github.com/PandaBunBuns/SOLIS_Deep-Dive/assets/87511092/1f774115-7792-496d-b8e1-6db1b170fbc1)

4. 2^24 Results
   
   ![image](https://github.com/PandaBunBuns/SOLIS_Deep-Dive/assets/87511092/116cafb3-130c-40cd-8cfc-3c13f10a91b2)

5. 2^29 Results
   
   ![image](https://github.com/PandaBunBuns/SOLIS_Deep-Dive/assets/87511092/f7cd9503-112a-4ef9-ae4b-5e6246704292)

