generate_combining_data.exe > data.in 
kp.exe < data.in > 1.out
combining.exe < data.in > 2.out
fc 1.out 2.out