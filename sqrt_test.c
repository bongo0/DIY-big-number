#include <memory.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>

#define BIGN_WORD_SIZE 8
#include "DIY_BigNum.h"

int main(int argc, char **argv){

    Bign a, b;
    Bign_init(&a, 2077);
    Bign_init(&b, 2077);
    //Bign_from_hexstr(&b, "1CF6C9C9BC5F884A294E53EDC955F57D1EFA78271816AAFD3571B9C977634B1F08432E269307615C66D97BE7B2E17D3C04657258EC100171CAB4B9EB895A63EEFB9048C425CEA92BA9463490C0A743F3EA62AB3899521BE541FA939FDC556606CDC807AB46C1FB60327EE14823B5E5C8787B499E077C1B816110FAF5396BF916253D8AA0C182F9A38CEA6BC188CF5B47E6F7EA8C28632ED0BECBDF10170C70782D73B32B0BDE8443AE648B17C6DC917CC258BE20AB93F921E85B01C83E3330DED2892AAF8B5810DB741CC45E4FF17365AB05A8E208A44BDA5133B1F857420B886FEE1200CE2CABC0644FEADEF8CEB260ED5644AB07FC8718C65592C9536B4667DD9FB1CEA42BFDF7CFC89C6FAE957AC4A37193B545AFF7C0E23CAC44F638DDAA16AC25A558B2FA23C6C05917D5AE4BC0E7B7D98670BD208B48078142E861E985450EB34426C829C55FCDE13172585747C692B985336F5A8078255F5BE70447B904BF0F6F1AA72C2C38FC03859FFD84ADFF3AE571DEF3D2A16D8A983433190572CECADC213335D6F49C5B5FE3C02CE76D34F5CA129625D9D82874BFC1657D06200BB8FD0D8A4919AEA408F071C654B96B5D128B3638D99BEE2D1BC8136105B5C6B42DD204AF751C95098FD0A604F47D77984A169A7008CFF8E68BBADDF3F077887E2330DC949EC5399AA246CE1C82A20224CDA1B8906647E3B48F0876094A3D92BBDE6484542B6026B743583BF8EA662959EE4B5B8BCB7B5FD5F6F34406F2F9C957B515DBC264D5EFF561A227DE5DA62F9C48CFB22B99B7050A5676429D27AA04401E39E18200000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
    
                    // 2^1000
    Bign_from_hexstr(&a,//"79C6D8FCEE9ED602BC694B4A9CDE5B6957D0F95655C658F47D1D9E6C8A76B354428D65E2243ABDFAFE2B9A6EEA91D5EC40682091EB34E45E2550915F68875D1831F8DCC57EC2E52AAA215BF709CD7542CD40AD0C8373D0D293F30BB4FA4A677C136CF41CA85876B2A80451B31D89C7B3AE21DC1FCEEE53AFC8D31E18102C5014505CA7669CAC1402CBAAAA455D4F0FB41787D6B5FEFA9212797107DEA79A73905672DF2B95B51185F6E5B996487A6CF170B8C423D990CF4001AEF3844B33399BA0DF83505317EFEDCA2769233035630BA95F1FA0F6A295275B2B6CE1B7AEE9D8D0C9445870EB236778F3A2DA998ED4379535296F5A20B09490EE8F0C25BB6D300BCF8658A4F21A73796329096A71D0043E8AB684DCBAB1F35852F4EBE8C79CEDC4CC20000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
                    // 2^2000
                    //"1CF6C9C9BC5F884A294E53EDC955F57D1EFA78271816AAFD3571B9C977634B1F08432E269307615C66D97BE7B2E17D3C04657258EC100171CAB4B9EB895A63EEFB9048C425CEA92BA9463490C0A743F3EA62AB3899521BE541FA939FDC556606CDC807AB46C1FB60327EE14823B5E5C8787B499E077C1B816110FAF5396BF916253D8AA0C182F9A38CEA6BC188CF5B47E6F7EA8C28632ED0BECBDF10170C70782D73B32B0BDE8443AE648B17C6DC917CC258BE20AB93F921E85B01C83E3330DED2892AAF8B5810DB741CC45E4FF17365AB05A8E208A44BDA5133B1F857420B886FEE1200CE2CABC0644FEADEF8CEB260ED5644AB07FC8718C65592C9536B4667DD9FB1CEA42BFDF7CFC89C6FAE957AC4A37193B545AFF7C0E23CAC44F638DDAA16AC25A558B2FA23C6C05917D5AE4BC0E7B7D98670BD208B48078142E861E985450EB34426C829C55FCDE13172585747C692B985336F5A8078255F5BE70447B904BF0F6F1AA72C2C38FC03859FFD84ADFF3AE571DEF3D2A16D8A983433190572CECADC213335D6F49C5B5FE3C02CE76D34F5CA129625D9D82874BFC1657D06200BB8FD0D8A4919AEA408F071C654B96B5D128B3638D99BEE2D1BC8136105B5C6B42DD204AF751C95098FD0A604F47D77984A169A7008CFF8E68BBADDF3F077887E2330DC949EC5399AA246CE1C82A20224CDA1B8906647E3B48F0876094A3D92BBDE6484542B6026B743583BF8EA662959EE4B5B8BCB7B5FD5F6F34406F2F9C957B515DBC264D5EFF561A227DE5DA62F9C48CFB22B99B7050A5676429D27AA04401E39E18200000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
                    //2^40_000
                    "45BBF7C62B78C7F64F99663932FD0E72F00A6C9516A9209E3368F3996AAAF0408E465539AB065EC98F21A29D05FE17ACEC6C51A9334617493E1A0611A9D8A25F3B29EC034AED2DB922F0757EF9BA4CE965458D93CD2715F471DD8887F058DF2AF534B665BF23140418ED1EFC5981F71574285998E17FAE683F400E7E80B71CE4D7B4FA6365F9E2D4ACAA0C4770CF873002AC8F24F5FE977493C1430AF727E5C240C6F75D6EBDB28E2154D72E4BAEF2D1F8640AFF769E2C79E365C77F385A4EEA260B51D8ADD6DC5F64868C4B850BB60191110E2430F2736253A487E11398988A98B33BDFAA3D49A476DE3DC6A887064941317D967724C03968DB658956A7207CA260456B80BA128A5B866E8300EC2FCFD2FA11CA7280C4CE507FA9C8059EA212351D6278418B4F9AAFFEB34BF38E5ED8E6199E75D6C8C2DA32F420F99091947D988C155847FAC26029B2486390D16E57CF5C9EF17DCE4D2F3626EA243706ECD5999D340665DF53B026CBA0C42251D4A7169DFDE06BCADCEE5F0E9FD5F5224925473DE2A614381C6CA9EEFBE525FFA98974995B2FE6A451829764C9DE6A783A4627063461DC0EE0C176F9F4FF54D670B95B659A48BB3C1516D587DFBDC6077D9CA04463D64B0F64AD00CE697BD0A00CA4CC03B10C8F2F986F5D352F382503F3892DA2BB82E5F67150407E31837C14D00E99C00AF3135992D7C53D1C3AF3222CACB09C43058B7AE2674F14B96D88E02289A4C68229EFB096468B3E1BA04C853E016CCC6F9CB0031FE8502CED1D4FE6776F8EFE34A4006E300489586DEFE777347E7BDAA7AF5D4D56D41E8C60A5A70A10B7819EF6E23B8F8751A713B07C4ABA04AE98343E0289E3AB2EAF89BDA7C049CE24DC807674075B19D608D8E44523BE04739393E0A12AA6640CD463CE9F672E7254A0C93309993CD2F9A53A429092DCCE0584FA5437E3A63CE3925E4E9CF87383477CACB4D650E2894A974FFF4BE9310E7200E2A2EEFAEE400A61F7DDDF6048848DB479E84157514F8FB5DFDB80155D5D93472055FA11CB4605294461ADA416DE06543DD28F0E28172DA3544AEEFCABEEDAE70A163765483A979AE8EFD11284B9AD9A9AB6FEE8EDAEE790EA404AB47FC375EA738D8AC8A2460B892FFE1E3EE53ABBAAFD68DBFB0FA234AC2E4054D0B692C366A9FCAE7763B95DBA6615FF1E1676100050D298BBB20BCBAA35EA05E5FADF3CD322EB954350AE3DD66DDACFF940EDC78AA1DDBF2C66B5FD91B323A09BD6B3ACB0AB6A830528FBF08BC9138302900EC783297D6946083E453F8E6D9858EEAAA86321FECEE4CBCE40596DE1BAA2778ADF71B811C666FCB8D3967D2DE14298D56B4DE3ABCF93C52E6436976D04413CD0E8F7C69D4E5BE7A2D6BC2CCBDECCE6D197DE73D99F9A64F175154E2CE019B2436B31796A670777502EE469519D4E4BFBE0D02D61EBD64A33317EFB9B9F2E9BD7D098D849BB81C67C707934564C50E89C5F8423B910D9AD925433AAB1EDF8573EFB76F7E07B3AEB3A986395627C9EED23F47727CB2B584F05CADB478B2BFB72EEB0D04928A427E634DF3CE8E2DD070D27FFBCCA08D349DEB789A8BD0C47729051EC2EA87C294929189B032AC826979331D0E492FDF2523C2156A7285D524464E1D1B952114B20C1C1388DF1D7E8E7AC57EFEFDF9D3D26745F5D7A33A6E29633F36C9468C6883031425FCCBA08066E54AD90DA5DC896A11210023026C9D8AAE0B2DD51F8DBB8010A6F3ED19F5B3870224EE652270BC1C9D4708016E1EEA52321FA778146A55DE07B69D54CFB2671F5A73E93FBA7CEB708A6D3B13FDA30E29A1D66390FCB7A3D6962B819E4FC964FEC67E8D9A0D2F23DB91847BD1EF2E26F1CDF924CCDC8BD8B20DEBF0C03B768F766FEE2CFDC7358FE7968A1491ABBC0EB85C8E73AA1121AA8883A727638850E16B19DDBC69DE311E6FB5D39417C14455F0478C4EAD7FAECAA8C117D26157AFD4589B37333551953404EA41FDD5BF02F7BD60CF93670264DBC305A13675FBBC86464E38D39242A681045F5AC47078E67282AF7A91603D7E92C2DE21B667E223C50239B9E49A7A98EAF5486ADA2BF3FC3A15750C734D2543E98565496086A739BDBF2F7DA8154ECE7CD8A15FEBB85B3D736AD015D98EE0FCA5622E9CE49921808AB5DDE6F8D31D3E63C1615B2D831120FC582989E372F4877CD3BBAC2F97FA1E3829910A42225F329C952C5E6E4579666DFA7272EB8CD61CA9A385386EA939B90BC5DEAD5822A1AACE8275D32AAD78377CDCEFE9A29E6DF4CE21D9671FD2938008A63B5AE059572F69BC121D895943547F0A9BA7831DD2D3655281F2413C5FF35782A7DA0D79D53F2BDCB2DCE7C18BA7E4A8D369C597FF61DA7D6899437F50405C00F2116D75D267C58E7D2A8DE6065E2DDDD72C0EA37CCC98D8D751C71478D948D346872AE9CF88C33ED57CCA4342FB892914E8ECCE396F828E22578213331567118393035965D567C8763212A0DFB6CBE54A0CB97C83EBEF94237D7968F95B024C85D89F2A24A5E749046B7C69B9FC5CB0939E56F5129E6C9E9F38A3B6D62D5230DAAA964CB43EB89173D264AB4613422C0E6E3F1E06A54ECEAE0F287199DA133C16717C2624C6D6D460214AF1237AE460E9A1BB0B104CB118EEBB5696F0652B3FAA2640C2F4264ED825291B589ADAB590F5114B425C02C1D31185F8F2B00C8800E9B23AEC9DC2F781A52537F0DA517A57FCD10866556CE8A35590F6A9DAD38CE9A7CD9330BF69942A4E384FB53F4F174F718F2F1AF4BF2E2565A9F67759F803B7B2FFE9DC40F7D8FC4910A31BCD43DF6282C822AD29B78C1D543DF9504E9595DA50C11E0B4FBA14673C0509C8DBDD47A569907FE04E4C4B3236E4463CCA0090A8C0DB6F7ADABE08D345C096C721FB9FD1DE4F0E1D80B9EFC030705ED17CFEDC5FA0EB6B61031DE6984B231F2240BB49D6E35F91A118E909335DB4DBCE00A5A0E024888E91C19E9D6EC74075B74814819320AF1250B6EB93A9615423E6F06A52430C5580C049AB36EC288CA2C802C25EBDAD4AE86A0B94D466E3DA04011614AA87E99C6C686528FD38239393BC6162AEB8E4D34AB83B34B2FE12C4B72F8229F64C390555108F88D311FA92F2ABB7D538BAA583F80BA8518F941E422B287665B9CF21BB1E7E761A28EB3AD723D66CCFFA47EF8E70DA7B992631105641AE8DFFFC9209ADD30C2362A871E49C4C229DD0495CBF0990B738661C3A537D33F5B02F3007DD8935EE99B55EEB8D0ABBC878D00C92A476DB1DB5B70B752BED6EDE8EFEB4237A2D7815E41AF8E0A1BF3AE21D9849CCD672FADA200320EAAA6A2D449F3D991792665982D07B87E003791A48C8658C0AE255CE401D34B50EF8244641285452E8A88253B3076898F8876D488668ADC7C70B27880D681F201A1A04F6DB5F2C0FBB35596ACC12EC008E8CAA10CCF922851118DAC2DD50B3E10855CBDB826A045F8A1D917FFFDD833756A4E3F6D8408528C6978D7D48EBCC124ADE840A68FD2F9C1EED24ED1492A4FAF65C0CA208F10D701616BC2778B5B53EA4ACAE41FA764B2DC4E57AAFDE99CE285191BD833D80610BD058A4EFD92A9CD9158BB9AE796D5997DFE8E9D3474B564380F6BF7B746054F60F42D5E63E230D2A9268E224963B9EA8BC9F0F98DBB46776B96650D0DB39CB9B6C5AC46AA84938BA29D57B635842B82CDD1E3084F27E422D258A3E36F3DE64FE1727F2A2D1F065EB842CD92C5442570CD70BEBB2EF92A35E7BAD17906CAE70411EC2A84A113B8927BB2EB4DB70769C7911996046630D6D0DA2BD3941ABA9E157C359234D8DDC1B0328AF682DBC934F56DACBED76C30772F268E2815A568AC0EE4C0CF1F6F9FBFA4942D510B02CACA214D2F49B129ECBC81E37C962A730FD181504C53844ED0CE2A0EF902F592C8A4E187789F7C470DEEEF0E73FD3EC37368D7E56CE33DFE4FC2821AE68F02AF522045B248D56C691AB7CFFFACDDD45060AC60F8B8479E85A28F9305BE64ECB7085A782477721263CB07204E70E5374D160DEE834ABA8CF51E90958A6CD37A5C2AC895D3CF32ED02AB7BC48A61FEC0F027DDBC1FAE253705B587E924137D1E1A364BB14DC3DD977120985FC7DC54502E1EFF96D158F3D1EED76DBC841BB0DEFDA1186BF22A83E99FB0ACDDE0B48B6C9D33FE594367FF1D7B69664A0086BDE393BCA2FBA119254CBC76B1B62614F52AF1C0D2A393ED39AC41856CB229CE71B3C7F7B3F3FD683937D1A8C6E4BD96D04BDD404F8E7F99B0175575B38506B7ADA7E91D57915D46433F3E896D25AFF289BBAEBF8EA4CD04D61D6C0AC8473EF59A4D72210EF096BE3D0484606C2EE2D592E00A3AD26EDCB82D3CFD255E7B6482897D37BB739F446AC615CD102446BF3EC12FBAFA7ED5411FB2616919EFD1BA43282590378DB7A920F5BA46CE6CE9E2153E4711DB6C975FCB16253612A825F56FF5CCA3CFF808CBE978D8AC841AA0BD146655557B18A07790A4919FE1AB1B5AF5C274D86259DF76885EF575AFE050FAC27F03FFD26F55F7A6BD3B2B6A6E33E83C7BD6F55CC728DCF69BF53BB91915FED2624BE7B3C39BE84A666F0BA1F37EB08140D259E65576A2C0C689E34ED2F0A79DD016A5EB28F0C6274EF03178109D390BF6E73C6FB4F39049C6753539771BC126B0DE36FA36F353A253758AFD40DF006A2CC441C89D71FB42ECF274B98DB58771F7FA6FCF9CF0DBDDA5CE04A5502B9CBC00E6DFF697BA28B663E694DE7FFF996421F6F18ED8E281DE6E918BC8F330BA7511F74B3FF7DFC7FFFDFD9457823319788F5BE95A690F8FC90639EEB44E1E510B1D61E6B9966CB8555AEAC4B45DD8A39F2EE2A93F44C96C6EEF62A7AF5945DC9B2AC757046A42D209B4B31780AE4C87DE79C3DC72F86AE75115F0C8958E0D73CEBD7F7086BB33791E39E8D1F51CC272541C67BD555E6A5BCCF3442150271A50AB32805936A559F4E4E3E7371A49EA432B315CA0AA49020A0CFD3156D66624AB823AE93B6ADAAEFD63EC40B01BD325FD7B0675657775F2B303FE699B3EF0EE4D15BD69B8940D3E3C6C73266C1536DC72513C29463877AE2F95EF61CFA96D417F11DB155176909AB11B7EEBE9BFAA64F283CBE5CDE63381E399A829823D7CD11A099B9006F160E46DF074061CE7D1235EE82E73F801B4ECCBA4635FC74D99C40336EAC13F490629D5A2D40608A9368170C30CB9F61E1D17D37630894DD329315B90A174CDE0E6BD944E74C64A6A9ABF07741CAE17F7F0411FAAD297CFA04442CC5793C7C187461D2BB74E90330DA17A20C233FCD413DBA0C12F297AA59FAD9E3246C7BD53FA32C7B15E2CD1068935E73F1BC4F1E1A09F2D6380026A3AA283001BEC42AE7C0EFE48B63E2C2A2657BFB4CF0FC489E44DC44E06A470FC2250BE4C53093568E0B2E9FDBCABF19B004AD6DF4C3C7BE821DB68702B5252C5FE58344352C7A1F7261E247D053B6DB6B583E6B1F0AA0DD2B4527BB174D7D50FAD2435B0479B4ED2A5C9E613BDC931D7467BF35428ECA0887F4D9ADADB26CDB5DF1B8B0D0BAA3F22A96E9F52CB239CFB5F13D169392A15B76705427955CFF33281725337543642776470110BEAD5B505E16D15D7929BD95681BFC4517B1026A37638108EF59CEEE1CD7A7DDDC2A7A30A9EA55EC3BF0B56D950A351A2979957C162E51CA34D1FBDB86125EDE0A9CA03045815C4086CDA47FD98AE7DEBA3D2524966E04FAF8996F20D629A027572723EBEB2562F1E29FF5A16F0217AEE3CDF0F05C059EB15D8773D4DB0AF20745C1957CA448DAC93CBFEDAE2C95FDC875180F5C49F6A4303632B59EF89C2DFD4237AED784DECC2975BD105B40FC4CDB0D83F818CE89930F594EA2EA31C8AFB5DFDC8F8CB8FC60D44613D92E46964B13C189ECCFDF860C2B4303DB818B188684F1BE7C2C93AEA5824DE7D506525CA8A24752CF7FC981947224BD1FA717E3EBAEA6935380BEAC2ACC6F21218C7192E9394551DFFBA7994795ECB46386900321DC03B2C147AFDF3111FB378E99A6901395D0DD19478DCC5B989FFC584BE234D06E2354EA8438AA1C22C0CA71E475888D60295E825BF3F89852BA815825DF249708195D3021748FDC885D3BF8D70A5DBC78D219E364865ADDF9F7C848535F851B678B1EB4D31C6CA7C2E0666EE201A68D9622CFEF35E15B8ADA95F56DE00B010A03FC14A764DF1665A155B9C8056F570EE62C94E8B7E88F2E8D6F1D2F8F5D9EE2429B5B5690CD10D80DA5EEFBE41765CE0767321CC71A66BFB8D4EEF3B1662D0B98C058FE85C1A8902097131526EAD82EF3950ACA479C8CA81A87F1B9336B6ACD9CDE92254E97BC84619F2492C749D30DC9AE884DC8AAEF35DEE86732EA17B8E2D0B64BA0849ECD0399619F7A0A6BBBD57777D97F75934671073E43B11113D295318C8FE5C35C9F30F5F194E55FE6A0F254273A810AD9B2B40F49BF763513955CF9AFAAE65EC7CA9D3F480537DFB429D7FAF0ABD01F127A8655F351735BDE827077743F62EE0B6878D4503E295E51B5703E53BFC166BACAF44DB107874B110E7A65BF0238F686F7E0109166D4719BED63D0797ACBF802BA556B1E367D6F2C0BABC6E39CC2A63D7C8D0EEA8EA81F9DEA55580BC633156D124FE4FAF4D11C28DF0825816359279A514205B2A29EF402E34BAC1624D9EEADC6BDB32BBC33968B5AA1A34502BA18EEA5B0569EF972BBBD4842BF85139C534953491BDCB660A4AB65ADA7FE74948613A1EF06640C7458AB05A43A12901A812BE907FE3DB383FF54D5A2DDE8E5475AB2135BB217148AD43450E918B11E27F8F3FD0F6EC0421363FA0D38EE98BA0A0EBBDE4CA6C249E15C1B5AF5FEF9ADD0BFF612AFD3364BBF2D462114D7296410E32268365405D29F284865D972E8191ACE5A566293659644CE0DFD214A8E580C5442CD16C4AFF40B543241EFAD24934F4CD98E49C26AF5F0E8E085B7703BAE6D845F9934BDF45324F466434B41546B8C4D52B5FE9B4A6ED58599340BF37C211D636A38CE1EAB6832EE86CE9C6140F85319196E6EAC63DF731AA71AD29B3A6A0F76486B539F28E36DFAAA8DC133D2F7B71A1A11AD28A610BA709BB463CDB88ADA0D55A129E255118C04A61C6C43078BCC7DC8B4956C3D5DD18D8DD44B78DA23A8F6824245C9624E1B4027C91F368AFD6B2BCD1A5E1E694F20FB8BC7367E075F14CE3B5D5EAAB8D185DEF0CBE2D288B3BF426AB2FB331260AD030EBC68B5739D7557AF74939B5740F2BCCD074100A082E56C9EDE1CEF67CF915851DDD1F277347B33C5FEA6CA317B88D67A3573EBE01E53F87AC3FCD30E3A7C081CC8E1C15EE0C198524BD274CB356E4BD6A53BB2A0D21E2D2817B8999840CE1D7F91F8EB27153D3BB994C6EA0EA8366FD87900824F2EE9802C425D9EADEB986D9A7F3B27130AF12633EDD3CCDC9635F7C665FA34D7F1A974AEA41FEEDAF1209D89693592F7C365AC2D3B5F72806A81CA2523202EDEB768D3094A596D2FD96725CDC12945306151A80E8ADCAFC3A1C3FA51BF9423D0ADA94FBD44A65B507DF265F8AE7A61FA702476C843C9D2B796B131DD506E90E72E3E39817BCE83BDE44CC9EF012C84C7860AEF8FB6FA975F21D49DDEA8FA7D3F617CDB9BC81A68952A8776D83626317F25754918F58B5675DA2A597870D5D603442DB0157E313611EE5B0BABBD0AA5579B6E65D396DEA7176D4E29583B7367F58D6F1AADD71A6B93AFB1BA642609458FBBAD8D3445EEC6431EF7445B74063EA23ABE475955A1D87BCF5042B3D6CE5F4569304C6B315410D697B026FC0D3680DB5330A4A3D3B2E60436C2E5EE7354A6E0D70888FB9FFF02203B65873DCE9B3E6496194BBE7C555AC7A3E0BC4BA5A563B8E962C59515A6562AB52A78DBB28DDB600D7B7E7E9FE395AD3C745F1D163F99CACEC83E85650BE1ABF95D39AC2F6DEB95EF04F40FBDAA7D01B732B90474194F60E6709A6A35E07336167CE35EF15848C00A11056C01F00AB10488B7FBC5B8DC55E0AF48F9556BE5F54D741FEF2DC6D394C8D7521D662F0B8F0F1F9903056B92EE689D1309F3BED1153EAAAF713A579F437D912D747D3A831E09172B58A68A15CBCCD8424F383765C6C160842FA40A61A4ECA874EE458B259246B6550BCEA18F2A526D500CB6908CA42CD628000E03A368446EB99B83FFC831548EF28D6FFFD60D53DCD6E49449A7C71E91D9CBF7BC2AFF735FF6988D1D4022EA41F6E3797D53B92B38160FDA57047FCE554E1C9897A1897E9A7A234F4B5021324C04498AC11B9A338E45CF52E6ABEB5A6E494A4A7509D63719C970E3FECC608D9E524FF1634917B8515639CDA3514C988FDC059ED7C32663242627233281907328BDBED63E18F36B7338C8EABCE94C708EBA23ED83AADED32A246D0136A5DD20C94F601397B9B07278E2BAD05EC30A0BAB3EC3ACE75604E22F2BD5C1EE7A1D56D1FE6A5E0B7ECCE4443710E056B042B202EF0B34013FCD3157928ED0BE2A9F233F832A0F9D88DF7220195D14BDBDE698D76D99F11B539B1336684575A5C54195C9C45E8B5971B54EFDD8FE33D3E45BE0A12F593004FB0ADA742163BA2FECA0D147B64C97A330EAFBD78C1378A9170F81C64722C34708A62B364EEA1CCDABB42DE8CB3B93282AA13EA6DEAF844994FA521CC0FBA10272C036012DB9CB3244B71A75183DF5F419E72DB85BB6323CC04854F655C50E59E9ED46D692BBA0A108B7BDF2D9D3F50FAE29B2E2A5670978CC12754C81DA2B7D7A599E2AC68D74E6718DF3D27E6958583CBD059DC74B32D7437AC779F1D1D8F1A8A7A454D9028C6250D1862DB8D4466F296CEE355C4816E4CD47AEF2A065516CD2450344CE1D2A60FD269EFFBA1ED7DF292ADB59AC78646795A4E967E510F4A16D05485BA24DC27B1F98B4F8BDD1C8F93708A517FEDAEE3070B4576C44C27283833DB0F034806A578EBBAB12D156F0A0BB47A5F2439254251CFA4F8FE837898ACBCB0ECA0AE247109394BA0D83AE9FB8C104CC98EF7DC62FEDCEE47034DF9397879C018098ED42F8CF5D89E9A3272D0107E8B01A186CFC4DBE1D2F055782862A1FF62448D420B168A9B407A1E87B12F1015D01CC2C9AEC6A35393D2CCB8D8A5193645359920BE07A329496A9B307071555255F13B461044135E858CD2541C95B6FE081EC1EE4502A63BDA4A8109DBD3CB0711EDD293D530D0CC3D1B1B31E28F5070ED6D9753219CE0BE5D19FE4D43CD48C63BF334BACBAD7DA4FF574E93137B3901368FE1AAD5DFB6D40F378FA8AB45CC55978F5340EF17B7BD9201C87FF20BC72D62561F3E6255EF609469CB4B9D3B96F34AEBBF8901F825F89FB6BD76AC973467255BF79ADA5533EF5E61CB1BF816FBD99F5C86951E5C68F093E2D0C8E794E56E4F56F7CF6F1C215C3024A4822F18E5D75815E67B5FB3DDE6ED65D6008C34203B7307A6073DA543C29C16870CF3A3E7FAB3A8A884911C593FAC0687C62A8CB7C6976BE0FB84D418979FCE2FAD6C7BD39DB139A138BE783A2CAD86EA2359CCD84DDF1B264ADAF95CD556077BC130F5A598C85BB88A54E6FD88220CAAD6D993B8DBDF42B7AA5C6C0F036CE53798920FA65F0BA9FDB141164B721DF57ED752FE2D37283FAD6D5AFECC707F82CD57005A12FA6E29E1737DD2F7A996ADD9552C17F560AD37D88F8D86EB96AB2FD454A6977D8EC76A86EEE6C4C6E274268005E5B9CFAD8EF5EA0510E59BD76473179D38949196FC9468D7A4964425F380A91C7FD8A6DEA1358F9306F8D9640659B52424057D2713FABF201B38844F7B36AF30006A58739A189D75D61BF9ABF362D7D7C735C02511CFF1A26C941A09F4DAC7FC7F39827249686F6C3D97557DA332AD672022DCFD229FB22A49745CF738B0A76B7737403B94B7807AE0E52F57A01955BD4EB66419C9416F23DDDEE858CF004853245D16FA2D9EBE2D64F39A9D39A3FBA3AFF61D6E047D9BF703E1A64870CF395F819A0421C7E5613E2EB90DC02BBA427DF4556C6E8F3AED16ADFB1147E6D746F692D5FB0EFCD9C3C43E6FBD218201E3CCA67DC98C5B97B017E6F557DF22D39CCC7C4FD0E46B9FE87E15B16F0C1D47B5F043A0E38C21C4DB9B0D2F2B18EFC83E0992B3B97EC104F6D93F0949F8CB81C38A9CB385E1E4E2A5926F8236E1631103EB5B3D155E01BFD78D7DD6FC7FFAB34321E766C5518FF0AC8BDE382662311FC732B9C2DD9E9462833D3C569B192951F426B21C9717D6B284D90253E8203E529921D1CFF5B6AF1F03346E496A66AA49A90E491A2446F50A07C3B828AAC63A3F50D95554FA3D4DBBA311D890C2C8EBAC01B3A18581F191D8F5DF91C4D2B3F094EAB00C7A0A47B5E785977796480FB558043C1CB597BE71670740253CFE4D48744A2231B9AC70FD941878F0694373C39F271B8DD476B7CE16DADF2E149D347992952FCDCE4FE742C980E18AF8758E5AB403A97EDB7A2FDC2EEBDC7FE69BF5F2D5782BF66F43DB48E1C96EB8A48E66469157DA472AE6949BCA6A0115AE61A0A479C1212B37D71A17EACE938C53FF34279CD4AF444BBA47071F1B43A9941AD8DCF0B598F920F99ECFB52A817CA91C01109513185FC4FD03D64D097BB2D1253F78476579452CBDE7B4ED094E74005A236732A082132304D18D9CF1A27225D945A800805C06E4B8F47F3C2B6DDCFAA44E0249B6D1C8B1DB865A7F08635A486C6049B44D723826112272BFF3D1AFD6F0A70F86FBB5C50ADAFBFDDEC7315411DEABF99694417A657D81B233A517154C24DAF18EE41C720D165904E6B35772D4AB9335389DFEEE7E8F0B51F22E88C7410FDCC9F06011DFC030353D78E3CA7FFC91438E52C276167CA5E2FDB07BCE5B31616DC8E867BC77BFDADBA4BA8A2CF5A7EFD080B2817038C84C5ADB8FF96E3BA54E6DFAE9BDFE11F82115C452EEEBE58F173D99A1E40F9DCD0C39C4D745824EBC20EEB52BD93EFC40177302CFAF00D036B06D625896B3AFA7098F199D3E3B72D60EDE24FB5444AF7B7A592BFC947468CFB904A2A5DAC7FAB5472DE142BAFA529A7D751DA28938A129CDBAB5F31A8986C00F2FE00A209E982D4560BAD63E5F65AF87FBAD7F994AB2124AF823F7D9808C064D6A8A7A28E4896EE9CCBA09E6EB991AAC8A1F264443A8D58BDC9474778BE21EF93DFA28E7ED5E5F75D60200E84FAD6AABEB3293545A9196BD8EA195BD0CA923FCF651723C04281E80441919CEBF4622BCFEA4C1149D9861F83DD6A06FBA3F52473C9DAD18B4F48827D8E8D003786AB367B53863880ADCE1EDC98E3B941D967AAE2A9EB8C89446BA4DC1DF8E84CD09AEC34BD6C7C057244DB0E3EF11170FAD7A67FB83CE8B696C6CD31CFB76FC6709F8262C070064F588315B831CCD90905A88332B425EBA24A52C826D6535597C2D2DA1165D686B99D322B76CA28B76059571895B660028D410C9CFC274BD7AE1AC4E3C909C68A5AD06E592BA8821801644E7D7BFB7483FB663D1BCCCCE884925F637348F8AA94FFC2BA470B78DDACE2019B656130390F8D028C51B3C4950C3AE7D4458C1151955EC41B3B8345980BFDFD7631CB62CF3B8B824228BB62A2827E7C17C9F6C4DC13249590F1970C4B9C5110E449A656656DEFF40F5253B30C10E55735DA22A7863C7F5CE87C7938324D6576D2AD700079EA4648DC46023875DAEF4F9C8958F79A41148E1F0BB39E48D4FAB908E21D670A3BDF7C99680FF4114DB42E407C9055ED83A8E97AD33400C984F4E576D3E2FF2A33315E33B61B1C622B5F0EACC4020BF53A68CD57CAE5F0385B33BFA22354C85D33C22F7E128504A259CE0C22D4D04CFC10B4F58784D6905A14D77621964713BCFD81F96F4B2FEDCCCE553538227FA4A164235979484F7206E42589C166489057939F19E8A833E4AAE957B322BC4E017D3EA1A008725C16EF2C87031B623A89B82F19230485FE0385A2393466FFDFFF552383443244CC4E9F80C14BAF218C4101C34759C20823C65AE6021932292A5C5D6AEE3E6CD2A333841DABED9670198E800AA712F561BB291C18A86D64EB61722522EBD24667EB67459DB76FA59EA5E014572B7F0EFA2DB77516F13E2BD6501D26FD4813B1DBD09DD57C29276620C3F2570F1C53944E1A718BD8C7A7DE8C32503644967803E16B9840260A0DE4055A47E72BC1A9631AF9F3FDF97A0D5D53F7773638D373C8E7D9F9F6048F17D746756087183770E630CC2000728650F3B5A4ACE8581539F1E3BE1FF89365B33B3AAA2195C9EA0E3DA205A31B03BEB0C7CD0747B7E67ECEB38389B3D13439F0B7AAB8CD8DD4DEF1689F7C3B62D13D27639D51A1E6E36B73907366E6627955DA183322E3234530404E96637BD0EBBA70037D0E9A91BB9BC1C723105D332048F4B3454348734DD3CC7FCB87C261500672FB84EBE7A38638124D4ED4BCD2A825CD89A1C85891136CED4112D6B9B1E4601F9D9573E8FDE93C45196B9ABEB958EBEF99F7B72280695E6DC9F235F9F539550E8D0E38E0316DCF72C023AE4773200927ECDFC256CE50341C1DE77F7C665C1946FD32C723420AA40DC4CB67AABA7B13236EE59E3B5186A67CD425C17850B71ABF163C020E6A8DDF9E1930A9312D637E1C7CEBF08BE15D474AF357B9DCD6B444BADA716784AE62A3E747F53D961F965F02213B0E4B25DC554A3C4E0E9AFE19B4704BE0CDB27B46A91920E02A1F577CD19D2F4B074BE3772790A0716AD0386917A5CFA74D2EFF88CA53AEFD23CD248D177E9F5CCDD9CB4A4FE016C8D1B2A52F0F3CE5D059F0CC415E860C714B8F98F3F08B358D1D3CB175B9FF1FAE179553CEF5E96779E025B468BA61FC7BA2953BFDD8E6C5737B316858C93F2D1228C92F8FDC21EEF8A44C44D5744E26835FB228FF6A2FBE014096BDD1D741DFBC07BC1F03D5F26363900A67D970F125F93A5720029CFCAD7A05CBB9E392A482492AC70BE2D369C531ADEAB1E883321BE836A183AB2F3537D7ED088B907263D257FC9FF5B8EB56EAE5F1D7382FE27547B72D1C0ED051C383947BEB2FFB33F5EC888DB29F4DBC3F82844C8B88974DA34F04BA8A26D7BCF638CBB2AB01FC05E7577839447E4839F6C44CF8631ADC37DE1FE5B52545B62A76460E2062953E07BAD1AF222875305B3842DA8043142A35FCC62920AD84FF7902867F03B64644E0476BF39C23EC96F321C67CF0E283B98DA555FD0B086B4814D3108809E05B85DC42F4368A5670897747E76656E3A35B41C8A244B94BE2E0FB7AC173A8387BCD37492125D3AF49D42120F002C0D7DD23EFDF46A8546B5EAF133C9203FF1CBF0BF5D2A15C82E9D36EC5C2527AF77DFA4FEC182A7A1080D04333126833A8625AA97DAA20BCF089E64F4D97C3AA83E4C5112F62DE4B4945FB3244A4CB5F26140B7D24D75F137E058A9807E0B5B06392DA37FF36DA3591325D269F620B79A6E9AD2879B888B5AAE161C6694DB848E1594866343C3E60868540AAE6460F2EB822BD52FD4F5F645AF2A2D01BE89D456383B538C3A3623F920EE061FB9F3CF3E64D9ACB7108B6237E3125C379C7C4F5CA912B136F7281761AFCCBDCA6D92E785C040F2B7CE91ABAF29EAE6494DC8A2D8156A11ECAD91B5DE7AEDB73C22DF0D669DC5FD18B305EACFCCA97B2C642C96EAAD0BAFB526FF018F756940A1102742CC7D9439B1EFD082A4366F68F464AA9FB8FB25D481DF2BF30851504ED1A07259AC3E3E05C8E22BE8F67BA67A017C47749009A4195681BABD42F6418912063D34EC1CA3E2D1F4625F1787E34114D6E745A75D7ABF0191FDF59918358736956094A3BDF08A002FBC82E7CD1B18360DBE3DD65F9293D498F84118E9F9D16204443DBEF6922D721BD801984DBCD8DE4028C7A9651FEFE0B00DB361AF83B4A6359BC1991000FF46E4F2ADA87066B276FA19CD48BAA646435952D30DA93B08C8DB18A3AF4399FB954ECB8DD5A99E1E77B7F357617050D94CA6CEC4547B53047A81C280EBE420EA39DFE75789B8A4659300F74230662AF7075B5414DDB8BDC770CBA3DA3DAA60FBAAF100F4E27A632F7B428C92F0145473CD9F3C0E4FCB02DEBF2BE19301C989BE64171CF9576833B98DE2464D2145E18F94AB12F90753407B3E43F1A2A7E982A0BC35C55FAB3BD7C64D497B57544E8ECDBBF9B182863F07CF928B108557DF5980A7EF6B8DA6D73A216DF015C653C83106B1E2776A0D7C4B05892DE80C7AD33ADE3EC82118D8DFBD725EB53D253278013725B9A3CB25C9C62584FDDD73097F8A98C5F0F666516D0DF0541E120039DA52CE727D4F7A3A695F0DFC7D9515895A1DC3F248FAA02485AABF9D874D69623608D18933820F28EB53A80B330A507E6B31A370A4FD070FF98F74464D50550E74D610EB8C5A25CE7388145946931FED15A1CE0799C83F148A4EBF8D0EB49640A999FEE1067D04953EF513E7EF40C851CFC3EAECED9BF60DDB2E449DCC1DA18114BF655B70C755450029DFE33C34A46360E97B70818B8D0CD2CDB1B7D10C98A5525EBA4CBA2B787D685C6C899FE9D77173C61B0C0AD4827C49163E27B476693E556D25F7D2F4AE0F073CA6837E69270ED9ABA4E0E163D05BD8CE7EB2A2185257ACC53932081F64F85A826900BD22CA5090F54CA6826F681A48C89C6B500DC7A995CB2804D63F1E1C37139679FC07AB45D088A037C4582F7BD9F23C7BA353D34044E51E1F34EE2BA7CAA0C1A91188622C81CC7FFD198A0ECB88C0FDB1116D8AA9F709F86CA043BB02AD30FA1B1CC38C39DD08164EEDF2305AEF55B1317A605E6E7A7200FEC8113BC224F6490DF52EDE28762153F919648B49C6E02898695BC961D30897B595D86581D284F2EA0F5A28640AAA38D23D465CB6C2F6DA00B0CBB8BDCA4BB9E17852AAB586F2824D203FC599CD02AEAF21D1F64080BD5023B42FED65C7E5E6F8022634FE319F86065DA39F8A16687CB965AF4E7F96F222E65AF12B89121C84EE76CE48BB262471C2F1C8B847F347EBD70785819234C9A5AA14E6E725EE8AAA0E24EC8F63A343633487FCA6071B5B8FB0C53F8354494CE1540C93B76164D51DB62D79D755E8F01A6CEC5FA9AD6E15B79090FD92479FCB4FB5342279AABFE58FE1087543694096A88B23B5607F6680ADE60F278CEB599B3EB5D8E647828622C0ED852947533762E3BDA3458D08F38E0E28D4454F67CC7E33EECF2BD5AA3450C34132471D6C23F7191AB800B0E59611E97CA93E7D5B9A459A9C47BEBF3ED57A5D13137A6F221EBA83B0DF27EBFD1AA1D81A7D387E19499FDDD657FC50BD2FABD58D5DAD30824FD66D4938EDF2D427EA7BBDEF80A3AF89E083EB4C71334B4AE990E849C5079A0CF7265041DC00619EDB6709D914563DB345352C4C08C14AFFA5A99F7996C884662B72BC93CB2CD64719254F7A980AC6115DE4766530BEC867338FA5A4909144B98365A5AA156E1607A56DCE77C882BA4C62DB58C7E4247B90DF23F201A432E7B2EC78A8C429003AE04104C60DB3FB9C6B284E43396DD5B9453699A77DCE408A04CFFF09EC8BCF192FA8F085EA944BE5F0A64E8153796062A460CDCACF25A59DB387BABCA9AA5C1E33779C144CA35072B232998CBC283D65E9B34FE44CD5544CCC1419A0355581BA1A89084EF4EC347B072926B81187F4C2F2A8C1BB9F04190D928910ED31416C3A26A936C83ECC15A7B3BB7297F2E5C4DADB91F13B4A999ACC9BAAAB9D83452F1AAB935227371C74D9CD5B8CB415A7077328B7A033D0CC4FC1F13B68945F7A1CB209C0FA31BDBA9137E0B31B7A8BEFE6F852824279F18F257B452309D52A5AAF48521D3EEC35EAF34C6FDB3CA707A5B116887CB4AB1F593ADA4FAF9F081D8DD62B13D5898FF621F226B15E7024C797AB223B9165162165F09679B053C17FDEC933546D376EFE8E8C602330537A7DD8CDA152D540B6FCDFBD2D79AAAE5C6F5E5C8FE0E6F42DC365BC7EBEAA1FCDBBE4F06F9995EDBD9C56408EC56D0F19CA4CE4D6F9FD4D61416653060C46AC00D26EDEDDBC636535CBFD35134445D0AEEAC5DD04FF85AD33567C9FA42CBDDC58B0AFB511560F73961C7ACAEBBF1EC427E1636EDA1107DE3DCC47125D9FD7F7C9D28FF981754D62A7CA83190C428A9DA0FFB5DE301F38F713EFECDF656B96EE243FFFB790038EBCAE53402148BD1C7E9BC91E5C77FE86976B49807B469556CCD3E91307939347534DE37FC53F82BC6F20812A76C193A5E5984518589C52E27951AE264C917877E74DA7445A6FCCAF4B1C5DAD262D7F87B988972D6E9E5CE261FCA69DC42774CD4E3163CD01705BEF6A1691C49F38E9220F476823DDD58FAE030662FFA7E2131588C40936F5466C2E468F0315DB32F243484042D1F70B55024A15B0EF8FA5E09C54F62D60616EFD77012E330FD83BF16283049953758EE54CA8335B7A3448354BBEE333476E9FF48AAB5BF55454E386359E87FA6337AE646E9DA239BD53261519834F8B9B5E020000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
                    //"1812F9CF7920E2B66973E2000000000");
                    //"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    Bign_print_hex(&a);
    printf("sqrtof2:\n");
    
    Bign_isqrt(&a,&b);
    //Bign_print_hex(&b);
    
    Bign_print_decimal(&b);

    Bign_free_data(&a);
    Bign_free_data(&b);

    return 0;
}
