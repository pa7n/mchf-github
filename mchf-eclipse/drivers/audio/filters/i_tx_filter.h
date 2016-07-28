/*  -*-  mode: c; tab-width: 4; indent-tabs-mode: t; c-basic-offset: 4; coding: utf-8  -*-  */
/************************************************************************************
**                                                                                 **
**                               mcHF QRP Transceiver                              **
**                             K Atanassov - M0NKA 2014                            **
**                                                                                 **
**---------------------------------------------------------------------------------**
**                                                                                 **
**  File name:                                                                     **
**  Description:                                                                   **
**  Last Modified:                                                                 **
**  Licence:		CC BY-NC-SA 3.0                                                **
************************************************************************************/

#ifndef __I_TX_FILTER_H
#define __I_TX_FILTER_H

#define I_TX_BLOCK_SIZE		1
#define I_TX_NUM_TAPS			89


/*
 	 * Hilbert 0 Degree, "Phase-added" bandpass filter
     * Kaiser Window FIR Filter, Beta = 3.25, Raised Cosine = 9.30
     * Fc = 1.68 kHz
     * BW = 2.40 kHz
     * 89 Taps
     * -1dB @ 809, 2570 Hz
     * -3dB @ 562, 2790 Hz
     * -6dB @ 363, 3000 Hz
     *
     * 20140926 by KA7OEI using Iowa Hills Hilbert Filter Designer
*/

const float i_tx_coeffs[I_NUM_TAPS] =
{
    -0.00136963387867902,
    -0.00154698180275283,
    -0.00159163053382545,
    -0.00147741661877843,
    -0.00120882701502872,
    -0.000828478315201928,
    -0.000418097593646548,
    -0.000091320092875327,
    0.000021974130050419,
    -0.000201673787010635,
    -0.000852848114713485,
    -0.00196364687958346,
    -0.00348826112570551,
    -0.00529485706179518,
    -0.00717256931124521,
    -0.00885513209567824,
    -0.0100597130451815,
    -0.0105363454629951,
    -0.0101205604704021,
    -0.00877998921294567,
    -0.00664532045021418,
    -0.0040173326042396,
    -0.00134475617619414,
    0.000827871099573030,
    0.001938042460603026,
    0.001499434597820090,
    -0.000801076170127474,
    -0.00501923657539354,
    -0.010897625153546,
    -0.0178510089292003,
    -0.0250004081740564,
    -0.0312564601726055,
    -0.0354449414126899,
    -0.0364600276636809,
    -0.0334252713705447,
    -0.0258393894626836,
    -0.0136844336323678,
    0.002522103222162365,
    0.021742633556248399,
    0.042504479356303283,
    0.063046761438677143,
    0.081512148546264832,
    0.096159368648113891,
    0.105568648975492965,
    0.108812511216631644,
    0.105568648975493493,
    0.096159368648114876,
    0.081512148546266205,
    0.063046761438678753,
    0.042504479356305004,
    0.021742633556250075,
    0.002522103222163864,
    -0.0136844336323666,
    -0.0258393894626828,
    -0.0334252713705442,
    -0.0364600276636808,
    -0.0354449414126901,
    -0.0312564601726059,
    -0.0250004081740569,
    -0.0178510089292009,
    -0.0108976251535465,
    -0.00501923657539393,
    -0.000801076170127733,
    0.001499434597819978,
    0.001938042460603051,
    0.000827871099573164,
    -0.00134475617619393,
    -0.00401733260423937,
    -0.00664532045021396,
    -0.0087799892129455,
    -0.010120560470402,
    -0.0105363454629951,
    -0.0100597130451816,
    -0.00885513209567832,
    -0.00717256931124532,
    -0.00529485706179529,
    -0.00348826112570562,
    -0.00196364687958354,
    -0.000852848114713534,
    -0.000201673787010652,
    0.000021974130050428,
    -0.0000913200928753,
    -0.000418097593646515,
    -0.000828478315201898,
    -0.0012088270150287,
    -0.00147741661877842,
    -0.00159163053382547,
    -0.00154698180275285,
    -0.0013696339
};

// trial with 0 degrees!!!
// phase added, 48000 sampling frequency
// Fc=1.50kHz, BW=2.70kHz
// Kaiser, Beta = 3.650, Raised Cosine 0.910
// Iowa Hills Hilbert Filter Designer Version 3.0
// DD4WH, 2016_07_24
//const float i_tx_coeffs[I_NUM_TAPS] =
		const float i_tx_wide_coeffs[I_NUM_TAPS] =
{

		-0.000675829974580901,
		-0.000775321733206631,
		-0.000805271934889941,
		-0.000740609080216212,
		-0.000571424809863288,
		-0.000310812490280582,
		 488.9699404346010E-9,
		 0.000294703584162428,
		 0.000484214205902836,
		 0.000475465809656165,
		 0.000188165085459235,
		-0.000423194149580655,
		-0.001349687058284244,
		-0.002514970750248195,
		-0.003773366542757180,
		-0.004922025542628025,
		-0.005727860583686991,
		-0.005966986460872474,
		-0.005471367240494044,
		-0.004174838643172011,
		-0.002149262655069977,
		 0.000378246395424234,
		 0.003034088509181957,
		 0.005336300605019817,
		 0.006760456353567154,
		 0.006826352412897128,
		 0.005193570718607052,
		 0.001750569629993906,
		-0.003319169301624403,
		-0.009508737721896792,
		-0.016007441037782504,
		-0.021771957640371112,
		-0.025644303951367561,
		-0.026503648390737589,
		-0.023432144978397278,
		-0.015870758657540535,
		-0.003740460401229463,
		 0.012492452065518142,
		 0.031821099733789958,
		 0.052777245796880867,
		 0.073578365127334053,
		 0.092325368347023831,
		 0.107225454572517670,
		 0.116809887876610230,
		 0.120116333624982294,
		 0.116809887876602042,
		 0.107225454572502099,
		 0.092325368347002390,
		 0.073578365127308809,
		 0.052777245796854146,
		 0.031821099733764062,
		 0.012492452065495137,
		-0.003740460401247988,
		-0.015870758657553618,
		-0.023432144978404623,
		-0.026503648390739550,
		-0.025644303951365029,
		-0.021771957640365339,
		-0.016007441037774923,
		-0.009508737721888778,
		-0.003319169301617154,
		 0.001750569629999520,
		 0.005193570718610547,
		 0.006826352412898407,
		 0.006760456353566453,
		 0.005336300605017613,
		 0.003034088509178859,
		 0.000378246395420868,
		-0.002149262655073061,
		-0.004174838643174412,
		-0.005471367240495541,
		-0.005966986460873027,
		-0.005727860583686712,
		-0.004922025542627132,
		-0.003773366542755943,
		-0.002514970750246877,
		-0.001349687058283068,
		-0.000423194149579770,
		 0.000188165085459759,
		 0.000475465809656334,
		 0.000484214205902713,
		 0.000294703584162108,
		 488.9699400243500E-9,
		-0.000310812490280988,
		-0.000571424809863621,
		-0.000740609080216433,
		-0.000805271934890042,
		-0.000775321733206627,
		-0.000675829974580823
};
/*
// trial with +45 degrees!!!
// phase added, 48000 sampling frequency
// Fc=1.50kHz, BW=2.70kHz
// Kaiser, Beta = 3.650, Raised Cosine 0.910
// Iowa Hills Hilbert Filter Designer Version 3.0
// DD4WH, 2016_07_24
const float i_tx_wide_coeffs[201] =
{
		-0.000110171112837058,
		-0.000215191676106024,
		-0.000349404033716016,
		-0.000496951746094190,
		-0.000637115651709324,
		-0.000747336640415393,
		-0.000807001210118930,
		-0.000801400114963688,
		-0.000725164708732548,
		-0.000584494175355709,
		-0.000397621019065366,
		-0.000193211657284225,
		-6.731480373302180E-6,
		 0.000124831265731249,
		 0.000169152629565774,
		 0.000104697245724197,
		-0.000074292912637529,
		-0.000354939210586125,
		-0.000705729393731337,
		-0.001079699782698907,
		-0.001420598860001278,
		-0.001671301059874509,
		-0.001783277746026863,
		-0.001725628885472922,
		-0.001492101415996081,
		-0.001104703813899759,
		-0.000612964396330499,
		-0.000088522768269239,
		 0.000384500540237483,
		 0.000722159397614641,
		 0.000854544998949087,
		 0.000738666366568531,
		 0.000368118465545143,
		-0.000222362933209255,
		-0.000958685009193057,
		-0.001735806314542762,
		-0.002431986456578192,
		-0.002927060659140451,
		-0.003122100716888928,
		-0.002957366391184722,
		-0.002425464411957004,
		-0.001577152712160757,
		-0.000518211398253738,
		 0.000602874422036065,
		 0.001615200699433123,
		 0.002351084212928152,
		 0.002673356919585794,
		 0.002500044722247771,
		 0.001822235291716940,
		 0.000711698392249346,
		-0.000683804743772797,
		-0.002157773305786353,
		-0.003473035374927932,
		-0.004397017985558934,
		-0.004739167257486619,
		-0.004384726505971721,
		-0.003319205664526024,
		-0.001638911085429426,
		 0.000455246396374910,
		 0.002681018366088089,
		 0.004712846192293575,
		 0.006229830588165904,
		 0.006966890480278101,
		 0.006761336787794098,
		 0.005587203265857816,
		 0.003570994150065774,
		 0.000984907660613053,
		-0.001783219282335870,
		-0.004280462349942326,
		-0.006053704386701811,
		-0.006720045103649730,
		-0.006032371940927658,
		-0.003929671876394201,
		-0.000563165775618498,
		 0.003707704003290906,
		 0.008351350932807226,
		 0.012729482477129751,
		 0.016184648966684857,
		 0.018138857370352073,
		 0.018189761228878235,
		 0.016190286058037750,
		 0.012298889831410701,
		 0.006990913948433064,
		 0.001026294370149727,
		-0.004625323241644382,
		-0.008895051261285708,
		-0.010748461471684751,
		-0.009326243981895398,
		-0.004073641409469179,
		 0.005159055689068004,
		 0.018059786439140576,
		 0.033851609217688650,
		 0.051346528754005590,
		 0.069052380559209328,
		 0.085321938965670419,
		 0.098527650095919780,
		 0.107241613104364406,
		 0.110399189880406076,
		 0.107426132449888842,
		 0.098313230288092343,
		 0.083628697746030919,
		 0.064466058948901367,
		 0.042333175031220437,
		 0.018995274586969532,
		-0.003709544175785423,
		-0.024060597134652702,
		-0.040628416865048686,
		-0.052412083218987278,
		-0.058924848579470578,
		-0.060219420607372891,
		-0.056851821845366309,
		-0.049790270526443803,
		-0.040282049358040938,
		-0.029696029207309495,
		-0.019360831602198387,
		-0.010418315895665185,
		-0.003709284676449769,
		 0.000296536964195334,
		 0.001520369759393477,
		 0.000244872198212814,
		-0.002957730720030519,
		-0.007327854240209992,
		-0.012035886094829340,
		-0.016298421211522331,
		-0.019478361596522272,
		-0.021156958377630559,
		-0.021170395594245318,
		-0.019608758592464137,
		-0.016780441299653556,
		-0.013149516262532890,
		-0.009256748582560672,
		-0.005636421543896653,
		-0.002740851541915539,
		-0.000882550728394041,
		-0.000200815520129123,
		-0.000655602105927875,
		-0.002047494260227691,
		-0.004058956516116312,
		-0.006309381620576754,
		-0.008415008029277367,
		-0.010044724981282397,
		-0.010964018193722168,
		-0.011061575734036889,
		-0.010355975806581812,
		-0.008982953406087438,
		-0.007166532628799022,
		-0.005179428417921703,
		-0.003299301522811309,
		-0.001767583834310825,
		-0.000756729367970240,
		-0.000350083616969358,
		-0.000536400790861641,
		-0.001218728772099963,
		-0.002235277697461324,
		-0.003388287881854928,
		-0.004476019145966429,
		-0.005322880049650393,
		-0.005803361780652197,
		-0.005856687675122848,
		-0.005490706080302640,
		-0.004775272359132256,
		-0.003826919781512536,
		-0.002787786895091998,
		-0.001802402923937431,
		-0.000995976427007529,
		-0.000457323050545061,
		-0.000228624209408082,
		-0.000303005837526218,
		-0.000629667288270294,
		-0.001125170919207243,
		-0.001688682726272838,
		-0.002218535544559282,
		-0.002627501438172705,
		-0.002854572422980392,
		-0.002871763742314763,
		-0.002685337454483747,
		-0.002331746541649206,
		-0.001869380504742496,
		-0.001367741970733447,
		-0.000895934671193270,
		-0.000512282356362102,
		-0.000256561584565188,
		-0.000145794764945257,
		-0.000173914155402102,
		-0.000314980583202455,
		-0.000529119767637795,
		-0.000769996538033533,
		-0.000992520819123322,
		-0.001159569364704958,
		-0.001246779863546185,
		-0.001244869234892962,
		-0.001159371545637672,
		-0.001008107863716669,
		-0.000817026508314411,
		-0.000615244043722063,
		-0.000430157157095143,
		-0.000283391698705431,
		-0.000188138600992614,
		-0.000148143491709299,
		-0.000158320335099411,
		-0.000206699262770281
};

*/
/*
//
// 0 degrees
// phase added, 48000 sampling frequency
// Fc=1.50kHz, BW=2.70kHz
// Kaiser, Beta = 3.650, Raised Cosine 0.910
// Iowa Hills Hilbert Filter Designer Version 3.0
// DD4WH, 2016_07_23

const float i_tx_wide_coeffs[I_NUM_TAPS] =
							 {
									 -0.000677103480385558,
									 -0.000780090493534493,
									 -0.000814190035208927,
									 -0.000753630467332200,
									 -0.000587590187077226,
									 -0.000328197121900482,
									 -0.000015387609888190,
									  0.000283472465160544,
									  0.000480590851789243,
									  0.000481549325951272,
									  0.000204532536166321,
									 -0.000397965458349166,
									 -0.001319175547417292,
									 -0.002484649001394270,
									 -0.003749900078371015,
									 -0.004912200344510958,
									 -0.005737297596068188,
									 -0.005998870760199724,
									 -0.005525450693709243,
									 -0.004246955929541380,
									 -0.002231529112179321,
									  0.000296501905426256,
									  0.002964742683216956,
									  0.005290432490315485,
									  0.006746256285973765,
									  0.006847330812018482,
									  0.005247436081126460,
									  0.001829052108313485,
									 -0.003229427830830281,
									 -0.009424298449721112,
									 -0.015945453077265786,
									 -0.021747235534664140,
									 -0.025666607989597402,
									 -0.026575674008559730,
									 -0.023548627412424115,
									 -0.016018916599795770,
									 -0.003901768455824901,
									  0.012339415457482095,
									  0.031697188609326056,
									  0.052699255918641857,
									  0.073556129349929431,
									  0.092359963475823911,
									  0.107308858507223409,
									  0.116926173245332360,
									  0.120244211522740271,
									  0.116926173245324130,
									  0.107308858507207769,
									  0.092359963475802415,
									  0.073556129349904104,
									  0.052699255918615059,
									  0.031697188609300112,
									  0.012339415457459063,
									 -0.003901768455843424,
									 -0.016018916599808818,
									 -0.023548627412431404,
									 -0.026575674008561631,
									 -0.025666607989594803,
									 -0.021747235534658314,
									 -0.015945453077258157,
									 -0.009424298449713079,
									 -0.003229427830823034,
									  0.001829052108319078,
									  0.005247436081129921,
									  0.006847330812019718,
									  0.006746256285973021,
									  0.005290432490313243,
									  0.002964742683213832,
									  0.000296501905422879,
									 -0.002231529112182403,
									 -0.004246955929543768,
									 -0.005525450693710718,
									 -0.005998870760200249,
									 -0.005737297596067882,
									 -0.004912200344510044,
									 -0.003749900078369763,
									 -0.002484649001392946,
									 -0.001319175547416117,
									 -0.000397965458348288,
									  0.000204532536166834,
									  0.000481549325951429,
									  0.000480590851789108,
									  0.000283472465160215,
									 -0.000015387609888606,
									 -0.000328197121900891,
									 -0.000587590187077558,
									 -0.000753630467332418,
									 -0.000814190035209023,
									 -0.000780090493534485,
									 -0.000677103480385476


							 };



*/

//static float32_t 		FirState_I_TX[128];
//arm_fir_instance_f32 	FIR_I_TX;

// *****************************************


/*
 	 * Hilbert 0 Degree, "Phase-added" bandpass filter
     * Kaiser Window FIR Filter, Beta = 4.50, Raised Cosine = 0.90
     * Fc = 1.34 kHz
     * BW = 2.59 kHz
     * 89 Taps
     * -1dB @ 586, 2262 Hz
     * -3dB @ 375, 2590 Hz
     * -6dB @ 281, 2801 Hz
     * -20dB >3350 Hz
     *
     * 20141203 by KA7OEI using Iowa Hills Hilbert Filter Designer
*/
/*
const float i_tx_coeffs[I_NUM_TAPS] =
{
		-0.000192875376876728,
		-0.000182740263881208,
		-0.000140891715454915,
		-0.00006838009139126,
		 0.000023805288625652,
		 0.000113204625330436,
		 0.000166732821526421,
		 0.000144525647240612,
		 6.867219960430160E-6,
		-0.000276440128730619,
		-0.000715671112495218,
		-0.00129179592920764,
		-0.00195053373657144,
		-0.00260215863827949,
		-0.00312874866340919,
		-0.00339942340417407,
		-0.00329258338096766,
		-0.00272248284860552,
		-0.00166595472984103,
		-0.000184104091196061,
		 0.001566403782619490,
		 0.003337021727061818,
		 0.004808684980596975,
		 0.005630882640480853,
		 0.005475266742216030,
		 0.004097459914051238,
		 0.001398159252556323,
		-0.00252676885539993,
		-0.00735733549494755,
		-0.0125498193984163,
		-0.0173711247134924,
		-0.0209669219262358,
		-0.0224580250716578,
		-0.021054384563457,
		-0.0161721630791137,
		-0.00753736501650615,
		 0.004740100057217369,
		 0.020135096635881311,
		 0.037726671975072013,
		 0.056269419247174567,
		 0.074310657942761607,
		 0.090340451113308615,
		 0.102956241234166010,
		 0.111021125206319293,
		 0.113795008726467584,
		 0.111021125206319737,
		 0.102956241234166856,
		 0.090340451113309767,
		 0.074310657942762981,
		 0.056269419247176052,
		 0.037726671975073518,
		 0.020135096635882685,
		 0.004740100057218542,
		-0.00753736501650524,
		-0.0161721630791131,
		-0.0210543845634566,
		-0.0224580250716578,
		-0.020966921926236,
		-0.0173711247134927,
		-0.0125498193984166,
		-0.00735733549494792,
		-0.00252676885540028,
		 0.001398159252556051,
		 0.004097459914051059,
		 0.005475266742215946,
		 0.005630882640480855,
		 0.004808684980597044,
		 0.003337021727061931,
		 0.001566403782619622,
		-0.000184104091195931,
		-0.00166595472984091,
		-0.00272248284860544,
		-0.00329258338096761,
		-0.00339942340417405,
		-0.00312874866340919,
		-0.0026021586382795,
		-0.00195053373657147,
		-0.00129179592920766,
		-0.00071567111249524,
		-0.000276440128730636,
		 6.867219960419110E-6,
		 0.000144525647240606,
		 0.000166732821526418,
		 0.000113204625330434,
		 0.000023805288625650,
		-0.000068380091391264,
		-0.00014089171545492,
		-0.000182740263881214,
		-0.0001928754
};
*/


#endif
