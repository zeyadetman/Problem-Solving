const F = n => !n ? 1 : n * F (n-1);
for(let i=0;i<=100000;i++) (!((''+i).split('').map(Number).reduce((d,c)=>(d*1)+F(c*1),0)-i)) ? console.log(i) : 0 ;
