char * convertToTitle(int columnNumber){

    char* ans = malloc(8);
    char index = 0;
    char i, j, tempVar;

    while(columnNumber)
    {
        if(columnNumber>26)
        {
            tempVar = columnNumber%26;

            if(tempVar == 0)
            {
                ans[index++] = 'Z';
                columnNumber /= 26;
                columnNumber--;
            }
            else
            {
                ans[index++] = tempVar + 'A' - 1;
                columnNumber /= 26;
            }
        }
        else if(columnNumber>0)
        {
            ans[index++] = columnNumber + 'A' - 1;
            columnNumber = 0;
            printf("Test");
        }

        
    }

    i = 0;
    j = index-1;

    while(i<j)  //reverse string
    {
        tempVar = ans[i];
        ans[i] = ans[j];
        ans[j] = tempVar;
        i++;
        j--;
    }

    ans[index] = 0;

    return ans;
}
