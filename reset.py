import numpy as np

x_0 = 0.5
dt = 1/1000
w=0
D = 0.5
K = 0.7393
k = ((((K)/x_0)**2)*D)
epsilon = 0
count = 1000
r_vals = np.arange(0,10,1)
mfpt_vals = []
def mfpt(r):
    mfpt = 0
    for i in range(count):
        T = 0
        x = x_0
        while x>0:
            if np.random.rand()<r*dt :
                x = x_0
            else:
                dx = 2*(-k+epsilon*np.sin(w*T))*(x)*dt + np.sqrt(2*D*dt)*np.random.normal(loc=0, scale=1)
                x = x + dx
            T=T+dt
        mfpt = mfpt + T/count
    return mfpt

mfpt_vals=[mfpt(r) for r in r_vals]
print(mfpt_vals)


