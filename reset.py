import numpy as np
import matplotlib.pyplot as plt

x_0 = 0.5
dt = 1/10000
w=0
D = 0.5
K = 0.7393
k = ((((K)/x_0)**2)*D)*2
epsilon = 0
count = 1000
r_vals = np.arange(0,10,1)
print(r_vals)
mfpt_vals = []
for r in r_vals:
    mfpt = 0
    for i in range(count):
        T = 0
        x = x_0
        while x>0:
            if np.random.rand()<r*dt :
                x = x_0
            else:
                dx = (-k+epsilon*np.sin(w*T))*(x)*dt + np.sqrt(2*D*dt)*np.random.normal(loc=0, scale=1)
                x = x + dx
            T=T+dt
        mfpt = mfpt + T/count
    mfpt_vals.append(mfpt)

print(mfpt_vals)


