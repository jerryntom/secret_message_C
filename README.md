# secret_message_C
Reading secret message from text file

The rule of deciphering is simple. Here we have an example file prepared for our program:

```
2475 2417 1621 2340 2344 1787 2240 1891 1664 2410 2302 1487 736 2094 1309 2123 2298 1575 1816 1852 1118 2449 1512 2306 2267 1534 1503 1325 1343 1380 979 1494 1250 1168 2139 2353 733 2059 2310 840 717 1014 2116 1221 2257 1213 1813 908 858 1732 2239 1846 1131 2473 1337 1228 1924 1956 1066 1157 1584 2351 1136 1573 1689 1365 1755 986 2028 973 2063 2180 1259 1211 1007 2147 1842 2022 2051 1621 1699 756 2217 1765 1623 2454 2294 1208 2003 1023 770 2400 1965 725 764 951 1604 1658 915 1354 2115 703 1157 1798 2082 1693 1085 1377 2171 736 684 2441 1373 1473 1006 1274 807 1313 1691 1359 1433 771 2444 1888 2146 831 2461 2476 1967 2280 1956 759 1842 1707 1895 1768 1991 2092 2333 2409
Sed dolorem est est. Amet modi eius dolore dolore dolorem. Magnam aliquam dolorem consectetur tempora. Dolor consectetur ipsum magnam sed labore quisquam. Labore numquam amet adipisci.
Eius consectetur labore magnam ipsum velit quisquam tempora. Quiquia aliquam adipisci ipsum magnam quiquia. Sed modi est labore sed magnam adipisci. Dolor adipisci quaerat tempora aliquam tempora numquam etincidunt. Labore est quisquam voluptatem consectetur.
Neque porro tempora consectetur dolorem voluptatem. Etincidunt modi quiquia magnam numquam modi magnam. Neque adipisci velit eius. Dolor numquam velit numquam tempora. Sit ipsum labore modi. Dolor amet adipisci quisquam velit.
Consectetur eius tempora labore magnam dolor dolore. Voluptatem tempora neque sit ut labore. Sed numquam ipsum labore amet velit. Eius est sed dolorem amet tempora. Amet consectetur dolor est.
Adipisci quisquam est adipisci aliquam quisquam ut. Eius consectetur etincidunt neque aliquam ut quiquia. Labore consectetur labore numquam amet labore tempora tempora. Modi neque dolore porro. Aliquam etincidunt sed numquam neque modi dolor non. Tempora ipsum voluptatem est dolor quiquia tempora. Voluptatem porro modi ut eius modi porro dolorem. Magnam amet consectetur etincidunt consectetur velit. Quiquia sit neque ipsum sit voluptatem.
"To see what is right and not do it is a lack of courage."- Confucious
Technology... the knack of so arranging the world that we don't have to experience it.-Max Frisch
"Sometimes it pays to stay in bed on Monday, rather than spending the rest of the week debugging Monday's code." - Christopher Thompson
You never have to change anything you got up in the middle of the night to write. - Saul Bellow
To live is the rarest thing in the world. Most people exist, that is all. - Oscar Wilde
IK
```
The first line is our secret message, ciphered char by char. Each number points to the character at exact position in text from file.
Program looks for these characters and prepares deciphered message.
