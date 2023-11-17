x=2
lr=0.01
precision=0.000001
max_iter=9975
iter=0
prev_step_size=1
gf=lambda x:(x+3)**2
while precision<prev_step_size and iter<max_iter :
    prev=x
    x=x-lr*gf(x)
    prev_step_size=abs(x-prev)
    iter+=1
    # print('Iteration',iter,'value',x)
print('the minima of the given function is given as ',x)
