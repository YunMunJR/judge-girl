#include <stdio.h>
#include <string.h>
#include <stdint.h>
typedef struct {
    char num[4];
    int blocksize;
    char format[4];
    char subblock1_lable[4];
    int subblock1_size;
    short soundformat;
    short channelnum;
    int samplerate;
    int byterate;
    short blockalign;
    short bitdepth;
    char subblock2_lable[4];
    int subblock2_size;
}WAVheader;
int main(){
    char inputname[101],outputname[101],vocalname[101];
    uint16_t l[2];
    int num;
    WAVheader w;
    int k;
    scanf("%s",inputname);
    scanf("%s",vocalname);
    scanf("%s",outputname);
    FILE *fpir,*fpow,*fpv;
    fpir=fopen(inputname,"rb");
    fpv=fopen(vocalname,"rb");
    fpow=fopen(outputname,"wb");
    fseek(fpir,0,SEEK_SET);
    fseek(fpow,0,SEEK_SET);
    fread(w.num,1,4,fpir);
    fwrite(w.num,1,4,fpow);
    fread(&w.blocksize,4,1,fpir);
    fwrite(&w.blocksize,4,1,fpow);
    fread(w.format,1,4,fpir);
    fwrite(w.format,1,4,fpow);
    fread(w.subblock1_lable,1,4,fpir);
    fwrite(w.subblock1_lable,1,4,fpow);
    fread(&w.subblock1_size,4,1,fpir);
    fwrite(&w.subblock1_size,4,1,fpow);
    fread(&w.soundformat,2,1,fpir);
    fwrite(&w.soundformat,2,1,fpow);
    fread(&w.channelnum,2,1,fpir);
    fwrite(&w.channelnum,2,1,fpow);
    fread(&w.samplerate,4,1,fpir);
    fwrite(&w.samplerate,4,1,fpow);
    fread(&w.byterate,4,1,fpir);
    fwrite(&w.byterate,4,1,fpow);
    fread(&w.blockalign,2,1,fpir);
    fwrite(&w.blockalign,2,1,fpow);
    fread(&w.bitdepth,2,1,fpir);
    fwrite(&w.bitdepth,2,1,fpow);
    fread(w.subblock2_lable,1,4,fpir);
    fwrite(w.subblock2_lable,1,4,fpow);
    fread(&w.subblock2_size,4,1,fpir);
    fwrite(&w.subblock2_size,4,1,fpow);
    fseek(fpv,sizeof(WAVheader),SEEK_SET);
    for(;fread(l,sizeof(uint16_t),2,fpir)>0;){
        uint16_t ll[2];
        fread(ll,sizeof(uint16_t),2,fpv);
        l[0]-=ll[0];
        l[1]-=ll[1];
        fwrite(l,sizeof(uint16_t),2,fpow);
    }
    fclose(fpir);
    fclose(fpv);
    fclose(fpow);
    return 0;
}