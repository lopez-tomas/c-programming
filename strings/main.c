#include <stdio.h>
#include <stdlib.h>

#include "main.h"

#define SIZE 100

int main() {
    /// Variables to test str_len & str_cat
//    char orig[] = "world";
//    char dest[SIZE] = "hello";
//    unsigned int destChars,
//                 origChars;

    /// Variables to test str_chr & str_rchr
//    char src[] = "Hello, how are you?";
//    char chr = 'x';

    /// Variables to test str_lwr & str_upr
//    char mayus[] = "this string has full minus chars.";
//    char minus[] = "THIS STRING HAS FULL MAYUS CHARS.";

    /// Variables to test str_cmp & str_cmpi
//    char src1[] = "hello123";
//    char src2[] = "hEllo123";
//    int result;

    /// Variables to test isPalindrome
//    char palindrome[] = "A luna ese anula";
//    char palindrome2[] = "Amor a Roma";
//    int answerPalindrome;

    /// Variables to test numericValueOf
//    char stringToNumber[10000];
//    str_cpy(stringToNumber, "-1581093\tabc3");
//    str_cpy(stringToNumber, "      -a");
//    long long int value;

    /// Variables to test decryptionWithDisplacement
    char line[4000];
//    str_cpy(line, "jN jmot k sji sorjdknodrj; ji ouq jmot so omrkdouq nes sjiio. lkksI vjmesA");
    str_cpy(line, "Estc cjcrededf tdpf pbredbl sc icac rcsflvcr cn bprfx. trcs hfrbs. Antcs ic efidodebr pdcnsb adcn lb cstrbtcudb ic sflgedfn, tfmcsc gn tdcmpf bnbldzbnif lf pcidif y lbs hcrrbmdcntbs ic lbs qgc idspfnc. Sd lb cstrbtcudb ic sflgedfn pcnsbib cstb rclbtdvbmcntc becrtbib cl cxbmcn sc rcsgclvc cn gnb hfrb trdcntb efmf mgehf. En ebmadf sd obllb efn lb cstrbtcudb f sc icmfrb efn pcqgcnbs efsbs qgc icsefnfec pfr nf prbetdebr cntfnecs sc efmpldeb icsbrrfllbr cl pbredbl cn egbtrf f ednef hfrbs. Oascrvc adcn egbnif hby qgc icsfogsebr sd cs cstrdetbmcntc ncecsbrdf scpbrbr cn pblbarbs f alfqgcs. Pgcic qgc nf scb ncecsbrdf pcrf rcvdsc tbmadcn tfifs lfs pgntfs pcidifs, yb qgc lb ncecsdibi ic scpbrbr cn pblbarbs pgcic icrdvbr ic blugn ftrf rcqgcrdmdcntf. Ngneb flvdic qgc lbs ebicnbs, pbrb scr efnsdicrbibs efmf tblcs y nfgn sdmplc brrby ic ebrbetcrcs tcrmdnbn cn abrrb ecrf Dcsbrrfllc cl cjcrededf ic mbncrb dnidvdigbl y lgcuf efmpbrtb sflgedfncs f bltcrnbtdvbs pfsdalcs efn sgs efmpbncrfs Sd cl cjcrededf dmpdic gsbr adaldftcebs dnelgdibs cn lb dnstblbedfn pgcic gsbrlbs, llcubr b gn agcn rcsgltbif y lgcuf rcmplbzbrlbs pfr sgs prfpdbs vcrsdfncs Usbr lbs ognedfncs ic adaldftcebs bl dndedf pgcic bygibr b mbntcncr cl efiduf efn gn agcn icsbefplc. Sc belbrb qgc sc cvdtbn lfs becntfs y lctrbs nf dnulcsbs pbrb cvdtbr efnoldetfs ic dmprcsdfn.");
    char group[1000];
//    str_cpy(group, "acefhijklo");
    str_cpy(group, "bcdfgaeiou");
    int displacement;
//    displacement = 3;
    displacement = 5;
    unsigned isInverted;
//    isInverted = 1;
    isInverted = 0;

    /// ############################################ ///

    /// Test for str_len() & str_cat()
//    destChars = str_len(dest);
//    origChars = str_len(orig);
//
//    printf("dest: %s -> %d\n", dest, destChars);
//    printf("orig: %s -> %d\n", orig, origChars);
//
//    str_cat(dest, orig);
//    printf("%s (%d)", dest, str_len(dest));

    /// Test for str_chr() & str_rchr()
//    for(int i = 0; i < str_len(src) + 1; i++) {
//        printf("%c -> %p\n", src[i], &src[i]);
//    }
//    printf("\n%s -> %c found at %p\n\n", src, chr, str_chr(src, chr));
//
//    for(int i = 0; i < str_len(src) + 1; i++) {
//        printf("%c -> %p\n", src[i], &src[i]);
//    }
//    printf("\n%s -> %c found at %p\n\n", src, chr, str_rchr(src, chr));

    /// Test for str_lwr() & str_upr()
//    printf("(original) -> %s\n", minus);
//    printf("(changed)  -> %s\n\n", str_lwr(minus));
//    printf("(original) -> %s\n", mayus);
//    printf("(changed)  -> %s\n\n", str_upr(mayus));

    /// Test for str_cmp()
//    result = str_cmp(src1, src2);
//    if (result == 0) {
//        printf("%s == %s\n", src1, src2);
//    } else if (result > 0) {
//        printf("%s > %s\n", src1, src2);
//    } else {
//        printf("%s < %s\n", src1, src2);
//    }

    /// Test for str_cmpi()
//    result = str_cmpi(src1, src2);
//    if (result == 0) {
//        printf("%s == %s\n\n", src1, src2);
//    } else if (result > 0) {
//        printf("%s > %s\n\n", src1, src2);
//    } else {
//        printf("%s < %s\n\n", src1, src2);
//    }

    /// Test for isPalindrome()
//    answerPalindrome = isPalindrome(palindrome);
//    if (answerPalindrome) {
//        printf("\n\"%s\" is a palindrome.\n\n", palindrome);
//    } else {
//        printf("\n\"%s\" is not a palindrome.\n\n", palindrome);
//    }

    /// Test for numericValueOf()
//    value = numericValueOf(stringToNumber);
//    printf("\"%s\" = %lld\n", stringToNumber, value);

    /// Test for decryptionWithDisplacement()
    printf("Line: \"%s\"\nGroup: \"%s\"\n\n", line, group);
    printf("Line decrypted:\n%s\n", decryptionWithDisplacement(line, group, displacement, isInverted));

    return 0;
}
