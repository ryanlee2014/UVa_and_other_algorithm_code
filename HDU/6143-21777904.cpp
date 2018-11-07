#include <iostream>
#include <cstdio>
#include <cstring>
#include <list>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <complex>
#define in(x) scanf("%d",&x)
#define ein(x) ~scanf("%d",&x)
#define inl(x) scanf("%lld",&x)
#define ins(x) scanf("%s",x)
#define inf(x) scanf("%lf",&x)
#define inc(x) scanf("%c",&x)
#define gc() getchar()
#define out(x) printf("%d\n",x)
#define outl(x) printf("%lld\n",x)
#define od(x, y) printf("%d %d\n",x,y)
#define ms(x) memset(x,0,sizeof(x))
#define msc(x, n) memset(x,n,sizeof(x))
#define cp(x) while(!x.empty())x.pop()
#define rep(i, a, b) for(int i=a;i<b;++i)
#define rvep(i, a, b) for(int i=a;i>=b;--i)
#define elif else if
#define el else
#define wl(x) while(x)
#define sn scanf
#define bl bool
#define mp make_pair
#define pii pair<int,int>
#define rtn return
#define ope operator
#define cst const
#define it int
#define cr char
#define ctn continue
#define stt struct
#define il inline
#define tpl template
#define cl class
#define db double
#define sf(x) sizeof(x)
#define vt void
#define pf printf
typedef long long ll;
using namespace std;
cst it INF = 0x3f3f3f3f;
/*
 * 输入挂
 * 场场AK buff
 */

class endln
{
};
class iofstream
{
private:
    it idx;
    bl eof;
    cr buf[100000], *ps, *pe;
    cr bufout[100000], outtmp[50], *pout, *pend;
    il vt rnext()
    {
        if (++ps == pe)
            pe = (ps = buf) + fread(buf, sf(cr), sf(buf) / sf(cr), stdin), eof = true;
        if (ps == pe)
            eof = false;
    }
    il vt write()
    {
        fwrite(bufout, sf(cr), pout - bufout, stdout);
        pout = bufout;
    }
public:
    iofstream(char *in = NULL, char *out = NULL) : idx(-1), eof(true)
    {
        ps = buf, pe = buf + 1;
        pout = bufout, pend = bufout + 100000;
        if (in)
            freopen(in, "r", stdin);
        if (out)
            freopen(out, "w", stdout);
    }
    tpl<cl T>
    il bl fin(T &ans)
    {
#ifdef ONLINE_JUDGE
        ans = 0;
    T f = 1;
    if (ps == pe)
    {
        eof=false;
        rtn false;//EOF
    }
    do
    {
        rnext();
        if ('-' == *ps) f = -1;
    } wl(!isdigit(*ps) && ps != pe);
    if (ps == pe)
     {
        eof=false;
         rtn false;//EOF
    }
    do
    {
        ans = (ans << 1) + (ans << 3) + *ps - 48;
        rnext();
    } wl(isdigit(*ps) && ps != pe);
    ans *= f;
#else
        cin >> ans;
#endif
        rtn true;
    }

    tpl<cl T>
    il bl fdb(T &ans)
    {
#ifdef ONLINE_JUDGE
        ans = 0;
    T f = 1;
    if (ps == pe) rtn false;//EOF
    do
    {
        rnext();
        if ('-' == *ps) f = -1;
    } wl(!isdigit(*ps) && ps != pe);
    if (ps == pe) rtn false;//EOF
    do
    {
        ans = ans*10 + *ps - 48;
        rnext();
    } wl(isdigit(*ps) && ps != pe);
    ans *= f;
        if(*ps=='.')
        {
            rnext();
            T small=0;
            do
            {
                small=small*10+*ps-48;
                rnext();
            }wl(isdigit(*ps)&&ps!=pe);
            wl(small>=1)
            {
                small/=10;
            }
            ans+=small;
        }
#else
        cin >> ans;
#endif
        rtn true;
    }

/*
 * 输出挂
 * 超强 超快
 */

    il bl out_char(cst cr c)
    {
#ifdef ONLINE_JUDGE
        *(pout++) = c;
    if (pout == pend) write();
    write();
#else
        cout << c;
#endif
        rtn true;
    }
    il bl out_str(cst cr *s)
    {
#ifdef ONLINE_JUDGE
        wl(*s)
    {
        *(pout++) = *(s++);
        if (pout == pend) write();
    }
    write();
#else
        cout << s;
#endif
        rtn true;
    }

    tpl<cl T>
    il bl out_double(T x, it idx)
    {
        char str[50];
        string format = "%";
        if (~idx)
        {
            format += '.';
            format += (char) (idx + '0');
        }
        format += "f";
        sprintf(str, format.c_str(), x);
        out_str(str);
    }

    tpl<cl T>
    il bl out_int(T x)
    {
#ifdef ONLINE_JUDGE
        if (!x)
        {
            out_char('0');
            rtn true;
        }
        if (x < 0) x = -x, out_char('-');
        it len = 0;
        wl(x)
        {
            outtmp[len++] = x % 10 + 48;
            x /= 10;
        }
        outtmp[len] = 0;
        for (it i = 0, j = len - 1; i < j; i++, j--) swap(outtmp[i], outtmp[j]);
        out_str(outtmp);
#else
        cout << x;
#endif
        rtn true;
    }

    tpl<cl T>
    il bl out_intln(T x)
    {
#ifdef ONLINE_JUDGE
        out_int(x),out_char('\n');
        write();
#else
        cout << x << endl;
#endif
        rtn true;
    }

    tpl<cl T>
    il bl out_doubleln(T x, it idx)
    {
        out_double(x, idx), out_char('\n');
    }
    il iofstream &ope<<(cst db &x)
    {
        out_double(x, idx);
        rtn *this;
    }

    il iofstream &ope<<(cst it &x)
    {
        out_int(x);
        rtn *this;
    }

    il iofstream &ope<<(cst unsigned long long &x)
    {
        out_int(x);
        rtn *this;
    }

    il iofstream &ope<<(cst unsigned &x)
    {
        out_int(x);
        rtn *this;
    }

    il iofstream &ope<<(cst long &x)
    {
        out_int(x);
        rtn *this;
    }

    il iofstream &ope<<(cst ll &x)
    {
        out_int(x);
        rtn *this;
    }

    il iofstream &ope<<(cst endln &x)
    {
        out_char('\n');
        rtn *this;
    }

    il iofstream &ope<<(cst cr *x)
    {
        out_str(x);
        rtn *this;
    }

    il iofstream &ope<<(cst string &x)
    {
        out_str(x.c_str());
        rtn *this;
    }

    il iofstream &ope<<(cst char &x)
    {
        out_char(x);
        rtn *this;
    }

    il bl setw(it x)
    {
        if (x >= 0)
        {
            idx = x;
            rtn true;
        }
        rtn false;
    }

    il iofstream &ope>>(it &x)
    {
        if (!fin(x))eof = false;
        rtn *this;
    }

    il iofstream &ope>>(ll &x)
    {
        if (!fin(x))eof = false;
        rtn *this;
    }

    il iofstream &ope>>(db &x)
    {
        if (!fdb(x))eof = false;
        rtn *this;
    }

    il iofstream &ope>>(float &x)
    {
        if (!fdb(x))eof = false;
        rtn *this;
    }

    il iofstream &ope>>(unsigned &x)
    {
        if (!fin(x))eof = false;
        rtn *this;
    }

    il iofstream &ope>>(unsigned long long &x)
    {
        if (!fin(x))eof = false;
        rtn *this;
    }
    il ope bl()
    {
        rtn eof;
    }

    il cr getchar()
    {
#ifdef ONLINE_JUDGE
        if (ps == pe){
            eof=false;//EOF
            rtn 0;
        }
        rnext();
        if(ps+1==pe)
            eof=false;
        rtn *ps;
#else
        rtn std::getchar();
#endif
    }

    il iofstream &ope>>(char *str)
    {
#ifdef ONLINE_JUDGE
        if (ps == pe){
            eof=false;//EOF
            rtn *this;
        }
        do
        {
            rnext();
        } wl(isspace(*ps)&&iscntrl(*ps) && ps != pe);
        if (ps == pe){
            eof=false;//EOF
            rtn *this;
        }
        do
        {
            *str=*ps;
            ++str;
            rnext();
        } wl(!(isspace(*ps)||iscntrl(*ps)) && ps != pe);
        *str='\0';
        rtn *this;
#else
        cin >> str;
        rtn *this;
#endif
    }

    il iofstream &ope>>(string &str)
    {
#ifdef ONLINE_JUDGE
        str.clear();
        if (ps == pe){
            eof=false;//EOF
            rtn *this;
        }
        do
        {
            rnext();
        } wl(isspace(*ps)&&iscntrl(*ps) && ps != pe);
        if (ps == pe){
            eof=false;//EOF
            rtn *this;
        }
        do
        {
            str+=*ps;
            rnext();
        } wl(!(isspace(*ps)||iscntrl(*ps)) && ps != pe);
        rtn *this;
#else
        cin >> str;
        rtn *this;
#endif
    }

    il iofstream &getline(char *str)
    {
#ifdef ONLINE_JUDGE
        if (ps == pe){
            eof=false;//EOF
            rtn *this;
        }
        do
        {
            rnext();
            *str=*ps;
        }while(*ps!='\n'&&ps!=pe&&str++);
        *str='\0';
        rtn *this;
#else
        gets(str);
        rtn *this;
#endif
    }
    il bl endfile()
    {
        rtn eof;
    }
};
static iofstream fin;
static endln ln;
ll dp[2050][2050];
ll factor[2050]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,227020758,178290591,674358851,789741546,425606191,660911389,557316307,146326063,72847302,602640637,860734560,657629300,440732388,459042011,394134213,35757887,36978716,109361473,390205642,486580460,57155068,943272305,14530444,523095984,354551275,472948359,444985875,799434881,776829897,626855450,954784168,10503098,472639410,741412713,846397273,627068824,726372166,318608048,249010336,948537388,272481214,713985458,269199917,75195247,286129051,595484846,133605669,16340084,996745124,798197261,286427093,331333826,536698543,422103593,280940535,103956247,172980994,108669496,715534167,518459667,847555432,719101534,932614679,878715114,661063309,562937745,472081547,766523501,88403147,249058005,671814275,432398708,753889928,834533360,604401816,187359437,674989781,749079870,166267694,296627743,586379910,119711155,372559648,765725963,275417893,990953332,104379182,437918130,229730822,432543683,551999041,407899865,829485531,925465677,24826746,681288554,260451868,649705284,117286020,136034149,371858732,391895154,67942395,881317771,114178486,473061257,294289191,314702675,79023409,640855835,825267159,333127002,640874963,750244778,281086141,979025803,294327705,262601384,400781066,903100348,112345444,54289391,329067736,753211788,190014235,221964248,853030262,424235847,817254014,50069176,159892119,24464975,547421354,923517131,757017312,38561392,745647373,847105173,912880234,757794602,942573301,156287339,224537377,27830567,369398991,365040172,41386942,621910678,127618458,674190056,892978365,448450838,994387759,68366839,417262036,100021558,903643190,619341229,907349424,64099836,89271551,533249769,318708924,92770232,420330952,818908938,584698880,245797665,489377057,66623751,192146349,354927971,661674180,71396619,351167662,19519994,689278845,962979640,929109959,389110882,98399701,89541861,460662776,289903466,110982403,974515647,928612402,722479105,218299090,96415872,572421883,774063320,682979494,693774784,611379287,166890807,880178425,837467962,705738750,616613957,338771924,497191232,896114138,560652457,661582322,224945188,262995829,859081981,857116478,279856786,408062844,406076419,367193638,985761614,767884817,77737051,801784560,410447512,813374614,702909132,777826615,11426636,685259446,721228129,931065383,593559607,860745086,578819198,495425745,893029457,6156532,502193801,37480384,220174401,383076669,3013247,750298503,574624441,230733683,144887710,656590378,773954850,358485371,772254339,469363737,95843299,823414273,87709482,892174648,749756145,185864756,68295241,98238739,131504392,111672419,928208089,687974198,753032165,71715287,506557931,290314197,546089425,174590825,187067364,817659471,309331349,303445769,964814732,112937795,848457973,113604679,263728612,162653895,519013648,956915940,591788795,26960558,818561771,201473695,830318534,283328761,298655153,103269519,567777414,629890782,707451727,528064896,419467694,259775012,452053078,972081682,512829263,412924123,354780756,917691336,648929514,519218426,957710940,848100261,607279584,78508462,651656900,271922065,927371945,976904514,655633282,147015495,44958071,431540693,956102180,821001984,4640954,508310043,709072863,866824584,318461564,773853828,371761455,53040744,609526889,972452623,799173814,723225821,3874155,305590228,289496343,139259591,348260611,756867525,848691744,101266155,835557082,267191274,448180160,518514435,443022120,614718802,151579195,204297074,912569551,137049249,515433810,979001276,524451820,229298431,88837724,892742699,387369393,840349900,206661672,18186411,619853562,246548548,236767938,893832644,930410696,321544423,971435684,402636244,780681725,194281388,661238608,964476271,643075362,439409780,96895678,723461710,915447882,785640606,114709392,933696835,539582134,739120141,300372431,244129985,722433522,26638091,388855420,42468156,647517040,474194942,832805846,958306874,489519451,339220689,9833277,923477502,390998217,790283925,694135631,736657340,609563281,873127083,489593220,264439147,891171227,489029295,502009550,325923608,280525558,857054649,820622208,558213940,216997416,487921842,951328535,606653379,794417402,449723904,783486165,414645478,809681447,114612567,824953206,255016498,147060381,88903008,228293174,394357308,362355866,900088886,638573794,779598451,904922263,451026166,549459329,212643744,563246709,391796933,174243175,189725986,238337196,60051478,782959006,982673239,237607992,685987666,694447544,195840153,519748540,446086975,523485236,185780714,716004996,214280883,140643728,555470704,516522055,116665689,899547947,490696549,683197147,686671136,988747143,744912554,619072836,345158054,224284246,637879131,78947725,342273666,237716550,915360466,711578771,423071394,228124918,271834959,480779410,254894593,859192972,990202578,258044399,151532640,644862529,48049425,448119239,130306338,850105179,401639970,606863861,183881380,837401090,513536652,714177614,946271680,243293343,403377310,688653593,15447678,754734307,631353768,202296846,159906516,912696536,737140518,467380526,896686075,309895051,356369955,461415686,706245266,10064183,183054210,455971702,737368289,956771035,564163693,365118309,226637659,304857172,440299843,717116122,485961418,615704083,476049473,354119987,329471814,620060202,251964959,45357250,175414082,671119137,48735782,122378970,717506435,18459328,949577729,771970076,635808197,608040366,165916428,258536202,902229110,617090616,548564593,613394864,753777984,577888302,416452176,881599549,524547188,599140122,522765386,657552586,256787840,287613719,776067801,597965522,458655497,764387515,350167935,494713961,513386012,576480762,864589772,86987059,495636228,512647986,721997962,982831380,162376799,204281975,462134806,189646394,425968575,209834628,494248765,664281698,947663843,540352769,25662122,986679150,207298711,477043799,24708053,528335066,189351697,717500453,42764755,316734785,823726196,293357001,547414377,258966410,602945692,561521296,351253952,752369730,174204566,871148004,302242737,554611874,540181425,349941261,414343943,921115587,959388563,227019335,708812719,793380997,342547759,324322556,458370547,356254978,809319893,159690374,848340820,971304725,180230004,103061704,207441144,443272953,45593686,541647240,612817107,849140508,109375794,906749744,159084460,541378020,692284266,908221578,720697998,363923522,819281897,701846632,479994712,196613531,29272489,792937812,859009553,202148261,385627435,115321267,612859231,132778909,173511339,782369566,322583903,324703286,31244274,433755056,109559692,871157455,350443931,592104988,197184362,141678010,649163959,746537855,954594407,850681817,703404350,467293824,684978431,565588709,378843675,825260479,749777538,850502015,387852091,412307507,307565279,914127155,864079609,845970807,414173935,638273833,664477235,173471099,480759791,839694748,190898355,956270620,957911348,43002811,628936576,966234409,667971950,236586166,954211897,223051884,21058295,656573222,631532535,809706350,984734695,314281677,311454037,640732448,434907794,175084834,434807109,973816812,488481268,844735329,917344075,314288693,459259162,992521062,667512257,603748166,679935673,833938466,933875943,522922384,981191471,457854178,112860028,484939649,611363777,627371454,844300972,962501388,738504183,631041465,29224765,334078303,211237785,626057542,900175080,728504100,450509755,575177363,905713570,416609984,874776027,334255451,683287462,999293262,474888472,317020697,180417613,591538360,879151833,605566485,569294094,970567518,896200922,943088633,145735679,884701203,949403596,749113557,78958680,850679027,665376978,686499745,426302291,842343474,708066168,962548572,349652428,833757979,492365420,136639914,76093131,591710464,208764552,166233017,498121245,545840935,26721664,736011124,880639351,137410283,42609708,235572009,981737748,718913567,909319027,906112184,298059463,274736280,217450848,351267027,149682364,249066734,11785215,333890217,774940233,302540697,519852435,802535369,620684620,306323295,752310997,848793393,883503040,569433124,254795373,855478464,660158704,87911700,944741410,351053939,2634663,134077016,736459220,4882454,969435081,120150411,922584286,828772112,106810765,371205161,17024731,960279329,389323593,23991206,744762405,684217429,479374977,963728237,3246420,688035746,381629444,752436308,274567573,440219140,702541058,919238277,563955926,467150839,5249506,399086000,833151662,847391187,655983283,337920422,866913758,675206635,549602585,963783662,324756002,393087771,731515248,787956453,550936813,398161393,631665856,442637251,454846959,348994181,88011024,513458067,60476466,9760396,403700900,990173371,519613195,945797344,114696834,327457551,905694736,143025346,289024806,451579463,325709522,18701196,326143996,49850509,619195074,414881030,850660769,880149960,651809429,592293509,810577782,929598726,835669318,731671946,529667681,285562083,293565850,686472980,274474950,282703792,889076915,56602629,546147347,255724802,873696194,831784350,110556728,279941051,667003092,302778600,803516696,772054724,165410893,531446229,958833885,703493734,68812272,481542542,722167619,172528691,173636402,356397518,390931659,311533827,53449710,959934024,259493848,215350798,907381983,791418522,896453666,530274270,443147787,468552325,410897594,491169384,314015783,406644587,772818684,721371094,596483817,922913559,78344520,173781169,485391881,326797438,209197264,227032260,183290649,293208856,909531571,778733890,346053132,674154326,75833611,738595509,449942130,545136258,334305223,589959631,51605154,128106265,85269691,347284647,656835568,934798619,602272125,976691718,647351010,456965253,143605060,148066754,588283108,104912143,240217288,49898584,251930392,868617755,690598708,880742077,200550782,935358746,104053488,348096605,394187502,726999264,278275958,153885020,653433530,364854920,922674021,65882280,762280792,84294078,29666249,250921311,659332228,420236707,614100318,959310571,676769211,355052615,567244231,840761673,557858783,627343983,461946676,22779421,756641425,641419708,61123214,245460001,196379281,164796745,620727570,451931052,94566179,322707767,612134628,255969954,785621688,49142691,781545640,487273416,582513782,833998375,176341439,515583649,379734656,329346411,262683279,462309262,942371722,988636580,352487409,652079107,685238206,424870840,192091301,854038651,513843021,285993962,431760681,440541032,959964935,523665702,41329173,899681280,768843382,597111687,593261820,178812114,501033600,79074739,633101681,224353692,898313886,432945941,160288931,303376374,848566848,692317852,10693053,270477785,354061180,888603469,253860160,584047404,506196510,568296848,962951514,654500714,734254117,246375021,389395531,95633141,40560733,318862543,864056087,540006622,347088116,78457748,185163016,865077798,958626347,481942155,51697302,729691171,336768000,709437459,901887817,842611169,547889643,912368861,920207262,345079539,101456268,384418814,632085520,973211984,774267117,499685849,156629135,352272493,738377140,261339777,689733367,327231667,627599520,359467170,773351405,233242346,266305839,1644198,816838783,423687677,22255156,658712680,512357010,716277124,783879199,673663191,787126340,858736628,491333521,328205600,605652638,119644545,882244924,114307964,139226748,212410164,536612506,152452523,509087178,232158417,642534132,778495828,921783666,615535293,170411511,905829108,304372182,158051973,388988102,890480785,476645461,422530824,262605169,369890567,45133993,543019649,671454467,143904872,771077292,654570451,792302047,562743593,592383835,241405483,857708994,80754172,109559665,431852528,789666354,854298840,423750964,703612882,487324533,296454325,183468917,190880063,993511722,447636316,496304493,691034792,437596622,112850919,922723394,586363427,631568215,197942800,186902776,423857491,32548439,276963998,986623371,242322904,698701821,468143012,876893308,487882804,165353093,778060747,1978741,346786812,635942967,500239511,784774421,881554459,931353326,173156822,576087204,848116767,499529474,437246725,384326164,422741252,866757606,109119920,53023003,733649165,579939321,246937598,559803511,123029541,496654951,959176615,644519422,868495167,747639880,139528218,247727251,740880614,169939710,646685918,16756697,409656806,371643021,404482449,873066778,887595254,528988047,481364999,672119652,18687584,929665414,629120405,188972334,435969196,678076524,390271723,205031092,8365757,331709825,993340837,762606773,107178366,793994550,553235112,564769190,443329073,58033882,194148704,715134793,57945841,258463223,562100050,62957536,696919454,846230857,481025551,725011189,164024643,850925530,762458204,409955722,724294671,886984412,600351301,42985262,247400266,466533774,698686213,838053264,975424804,863218023,560445506,205342137,784512170,114961091,230506730,435065239,273110608,216022764,645044939,722381342,203348615,82876765,82258458,373083963,293637220,736550628,730999737,334655472,366933982,244031530,312608442,952278924,439803364,786138955,691522755,138915957,757247105,634994115,952367286,220361297,28961504,620993437,291462451,192646098,825217846,258845813,534937793,93814979,522361720,726763266,606345278,705963351,811983342,510153914,321930485,694723851,867133830,280978470,767663937,13397952,658500617,562307747,246220846,257735291,726052322,567215286,993033414,769264345,44514330,70515497,644579365,645970093,140217677,629726785,796071754,163640655,296632244,4042968,401405213,678766029,188940446,991255430,282266904,519915618,726754477,31255779,7766682,446187220,567993920,87804885,360984154,967620344,287455258,352050842,972735059,110525615,651681667,28652604,852930758,427030507,907424453,189822996,159272754,770216682,35113541,859756054,707249452,395495225,246473570,929367838,375193487,639880112,635747308,609553171,306944760,435152533,899576163,917215473,88482014,839732431,151281819,617626945,325178136,71002673,125693400,833970989,215840698,939364644,959387477,670421289,544742622,647496666,20359440,319980844,413331733,771100044,913453818,268067192,221797414,850985195,677294287,534700884,581232364,306536266,763841929,670218890,987314980,177537191,617288803,525339745,678355787,803297198,649041256,797205811,654597257,945917673,527580263,526066923,910757760,543736890,18904623,825659855,436985896,956953876,788402152,896254449,266326444,515180047,646741884,900662014,145346990,700847261,211576216,765562982,286182552,99594146,818004370,836262739,873284804,910254570,946062504,383933729,864565896,839447421,483172612,218074237,899196030,338254257,115652199,348730784,962171704,186789338,844538210,424934135,4359701,334645511,574569592,998750515,180739662,337685693,345736950,430206522,101517724,317393728,29627088,344429443,244701024,486997654,938555773,861309359,402130164,729206786,933967923,866805122,937130659,393451047,946839225,587847103,662317959,243618597,68283846,991807534,875140051,82406459,126371384,408761163,601561650,319043999,99379196,776863423,972765339,447579635,893651488,434359284,64047192,622456991,950738051,353376298,650938112,454346846,611570548,744245040,367552188,695830331,137149847,136218599,872771468,521050149,701518906,188983943,987784056,566130074,856405762,29097324,995153587,667366596,393019274,424195945,81048119,949995669,93415448,898064525,58068445,322104229,242633108,530220901,56647468,387388098,154233411,514416952,29097154,489548158,8676497,283716816,654159074,825853428,859149690,794764924,758914724,451922626,56993923,713646888,16199827,963933239,385044136,123097690,62832030,75485671,700846554,209611450,478522332,231087081,184973044,893189242,229693882,714596254,482570946,397815780,1349347,100933265,254025771,26174217,831778240,405823554,896386917,52741464,487649122,170870589,583340505,94564937,277820180,899859375,779208866,137119918,552509591,97580560,591800369,85574651,865649038,128523371,809878024,797390950,877692187,631337938,776610930,375093587,148237650,956673612,284338013,244423474,144473996,569178041,993078862,988458389,625744277,810626289,138295622,581515550,98811304,801651389,38910655,218136911,19055157,507306147,704441810,220213527,222494837,104210886,362681747,829563355,937865509,25593418,205402693,903736113,822603964,860184650,338015384,894841345,63603398,846693852,950642953,90930134,306816051,348815192,778237469,79403346,951033008,428627185,947797938,67234332,457491733,254027842,65379562,634064880,793876922,401004554,241436651,748921627,235773197,960720794,660649561,804622905,581554967,331694169,641821690,513029292,420150147,146986978,940564101,109063504,736653339,741347513,223387889,813402163,740363875,821476814,722640850,970598385,310914311,185009722,746116934,807984847,254836633,283644452,417075927,597261750,843545049,502496757,159591303,38700239,551998204,284996029,943365105,363079423,68791007,87353906,230437622,983014155,531712251,681438690,454113819,457096767,922563191,828713221,895627971,341864644,700056471,595145382,415107031,285556397,19194762,419952794,720216897,886764308,405198636,1285946,178392510,375302336,512757404,149308498,525827833,381482016,519422664,537945283,582865261,619532539,683439071,263607900,715074257,631748159,25848019,174264163,991716651,827177989,128707256,475527988,54965727,266221147,835485060,527837982,825646734,286725813,168394909,807636366,749812522,926966369,90008970,265472165,204953584,954837097,958492073,232782618,713926326,806461661,791587080,820400043,573664608,308087915,840616702,151201154,787603818,643029919,872051234,241187768,149088916,861978775,290973079,748019306,41699134,848386594,979755938,593123571,966241991,889714404,779624902,682443644,6143197,781310665,981518143,527365183,107985225,946009452,976623872,834626559,611986668,932488138,909063924,497814632,140633959,500203817,360342268,445467633,477704894,15361352,220315555,619476285,950921904,886367791,189185798,183160694,659711657,627029592,112665948,658051988,648634412,515148504,24924703,490594547,201854810,714542950,602785661,383539983,536564768,987492768,587027873,540968925,498244660,349158442,88557443,137723958,627674755,186876342,377413248,721254895,701311697,464980843,825434906,909994907,450790541,578501889,931407997,917054785,869149237,29257189,14026097,429313686,775020958,663028928,60524820,973597177,999655403,373165331,160897667,994649563,251491102,468275740,134943782,272400428,403178049,606290371,298790432,487696306,484233736,631964414,758798349,877363987,85540895,967541233,405691356,255015757,718958090,163918256,609588933,253217799,427182496,297334619,285033600,886988325,380436491,666193963,126435007,778326312,903667127,687840373,880361885,310561488,780994727,745208449,106871663,460676805,937497705,808221401,291795339,31122078,949308837,562350955,222172784,352239262,278458293,881629398,883703942,642656041,766788263,660830035,73816861,258979687,327930043,868826327,918178049,420185912,109137213,68821792,384968057,124910149,80898773,332388495,219920198,549570332,489638900,948597839,952707502,664458685,826905865,678979774,629723420,66425716,810305229,528398210,842999153,169382048,487124857,50096968,184238535,237452585,634813513,50106783,403314167,313482759,498134475,942437182,170130670,779446762,743305004,455852704,590363951,366230360,964904140,791415171,351457024,743110297,285539671,950624820,199641625,511558944,216283487,913142596,886342412,209131158,786607494,792630333,191271328,962389136,411019481,678612260,78877143,469516355,44624214,347853488,444348057,702180389,825584362,808066718,649421951,527998071,372246707,275346640,273864415,666283451,587586574,31051570,488457940,4518396,810872144,11541870,529730086,562850720,810299187,134899497,863414291,701755664,37580494,620187235,566972095,832270518,914744892,644210431,229277629,530537835,37376309,519199292,784199509,88822413,980152392,880351115,52386628,358816323,303416646,247871657,794390809,510618403,3194064,321052614,684171275,343286290,393422020,155860200,226634637,869751302,326073683,908403592,906328261,686898515,928035288,718245479,744984158,753416506,312502450,442383389,997238270,484811253,652876718,100550147,100292593};
ll power[2050];
cst ll mod = 1e9 + 7;
il ll quick_pow(ll a, ll b)
{
    a %= mod;
    ll ans = 1;
    wl (b > 0)
    {
        if (b & 1)
            ans = ans * a % mod;
        b = b >> 1;
        a = a * a % mod;
    }
    rtn ans;
}
il ll mul(it x, it y)
{
    rtn factor[x] * power[x - y] % mod;
}
il vt init()
{
    //factor[0] = 1;
    //rep(i, 1, 2001) factor[i] = factor[i - 1] * i % mod;
    power[2000] = quick_pow(factor[2000], mod - 2);
    rvep(i, 2000, 1) power[i - 1] = power[i] * i % mod;
    ms(dp);
    dp[0][0] = 1;//Stirling
    rep(i, 1, 2001) rep(j, 1, 2001) dp[i][j] = (dp[i - 1][j] * j + dp[i - 1][j - 1]) % mod;
}
int main()
{
    it T, n, m;
    init();
    fin >> T;
    wl (T--)
    {
        fin >> n >> m;
        ll ans = 0;
        rep(i, 2, m + 1) rep(j, 1, i)
            {
                ans = (ll) (ans + dp[n][j] * dp[n][i - j] % mod * mul(m, i)) % mod;
            }
        fin << ans << ln;
    }
}