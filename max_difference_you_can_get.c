long long maxDiff(long long num) {
    long long len=0,temp=num;
    while(temp>=1){
        len++; 
        temp=temp/10;
    }
    long long min=0,max=0,maxno=-1,minno=-1,first=-1;
    //getting the maxno
    temp=num;
    for(long long  i=0;i<len;i++){
        long long  digit=temp/pow(10,len-i-1);
        if(digit==9){
            temp=temp%(long long)pow(10,len-i-1);
            continue;
        }
        else{
            maxno=digit;
            break;
        }

        if(i==len-1){
            maxno=digit;
        }
        temp=temp%(long long)pow(10,len-i-1);
    }
    //replacing the max no in the sequence and creating the maximum number.
    temp=num;
    for(long long  i=0;i<len;i++){
        long long  digit=temp/pow(10,len-i-1);
        if(digit==maxno){
            max+=9*pow(10,len-i-1);
        }
        else{
            max+=digit*pow(10,len-i-1);
        }
        temp=temp%(long long)pow(10,len-i-1);
    }
    //finding the the min number in the sequenence and replacing accordingly
    temp=num;
    long long  firstdigit = temp/pow(10,len-1);
    if(firstdigit==1){
        for(long long i=0;i<len;i++){
            long long digit=temp/pow(10,len-i-1);
            if(digit==0||digit==1){
                temp=temp%(long long)pow(10,len-i-1);
                continue;
            }
            else{
                minno=digit;
                break;
            }

            if(i==len-1){
                minno=digit;
            }
            temp=temp%(long long)pow(10,len-i-1);
        }
        temp=num;
        for(long long i=0;i<len;i++){
            long long digit = temp/pow(10,len-i-1);
            if(digit==minno){
                temp=temp%(long long)pow(10,len-i-1);
                continue;
            }
            else{
                min+=digit*pow(10,len-i-1);
            }
            temp=temp%(long long)pow(10,len-i-1);
        }
    }
    else{
        minno=firstdigit;
        for(long long i=0;i<len;i++){x
            long long digit=temp/pow(10,len-i-1);
            if(digit==minno){
                min+=1*pow(10,len-i-1);
            }
            else{
                min+=digit*pow(10,len-i-1);
            }
            temp=temp%(long long)pow(10,len-i-1);
        }
    }
    printf("max : %d and min %d",max,min);
    return max-min;
}