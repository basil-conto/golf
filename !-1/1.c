f(i,j){for(;!(i%j);i/=j++);return 1/i*--j;}main(i){for(;~scanf("%d",&i);printf("%d ",i),printf(f(i,1)?"= %d!\n":" NONE\n",f(i,1)));}