// Literal transcription of Ghidra pseudocode FUN_140003f30 (ev_571db767...), uint32 arithmetic.
function f(p){ p>>>=0; const u=x=>x>>>0;
 let u2=(0x3fffffff<p)?1:0; let u3=u(p - u2*0x40000000); let u1=u(u2*0x40000000|0x10000000); let u6=0; let u5=u1;
 if(u1>u3)u5=u6; let i4=(u1<=u3?1:0)*0x10000000; u3=u(u3-u5); u1=u(i4+u2*0x20000000)>>>1; u2=u(i4+u2*0x20000000+0x4000000);
 u5=u2; if(u2>u3)u5=u6; i4=(u2<=u3?1:0)*0x4000000; u3=u(u3-u5); u2=u(i4+u1+0x1000000); u5=u2; if(u2>u3)u5=u6;
 u2=u(((u2<=u3?1:0)<<24) | (u(i4+u1)>>>1)); u3=u(u3-u5);
 for(const k of [0x400000,0x100000,0x40000,0x10000,0x4000,0x1000,0x400,0x100,0x40,0x10]){
   u1=u(u2+k); u5=u1; if(u1>u3)u5=u6; u2=u((u1<=u3?1:0)*k + (u2>>>1)); u3=u(u3-u5); }
 u5=u(u2+4); u2=u((u2>>>1) + (u5<=u3?1:0)*4); if(u5>u3)u5=0;
 return u(((u2>>>1)+1) - (u(u3-u5) < (u2|1) ?1:0)); }
const out=[]; for(let n=4;n<=40;n++){ out.push(`n=${n} f(3n=${3*n})=${f(3*n)} sqrt=${Math.sqrt(3*n).toFixed(3)}`);} console.log(out.join('\n'));
for(const x of [1,2,3,4,5,8,9,10,15,16,17,24,25,26,99,100,101]) console.log('f('+x+')='+f(x));
