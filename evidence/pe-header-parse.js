const h=process.argv[2]; const b=Buffer.from(h,'hex'); const pe=b.readUInt32LE(0x3c);
const coff=pe+4; const ts=b.readUInt32LE(coff+4); const opt=coff+20;
console.log('pe@',pe.toString(16),'machine',b.readUInt16LE(coff).toString(16),'nsect',b.readUInt16LE(coff+2),'timestamp',ts,new Date(ts*1000).toISOString(),'characteristics',b.readUInt16LE(coff+18).toString(16));
console.log('magic',b.readUInt16LE(opt).toString(16),'linker',b[opt+2]+'.'+b[opt+3],'subsystem',b.readUInt16LE(opt+68),'dllchar',b.readUInt16LE(opt+70).toString(16),'osver',b.readUInt16LE(opt+40)+'.'+b.readUInt16LE(opt+42));
const names=['export','import','resource','exception','security','basereloc','debug','arch','globalptr','tls','loadconfig','boundimport','iat','delayimport','clr','reserved'];
const dd=opt+112; for(let i=0;i<16;i++){const rva=b.readUInt32LE(dd+i*8), sz=b.readUInt32LE(dd+i*8+4); if(rva||sz) console.log(names[i],'rva 0x'+rva.toString(16),'size',sz);}
