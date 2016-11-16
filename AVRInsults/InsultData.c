/*
 * InsultData.c
 *
 * Created: 16/11/2016 6:36:37 PM
 *  Author: Chris
 */ 

#include <avr/pgmspace.h>

#define P_STR(NAME,STRING) char const NAME[] PROGMEM = STRING
#define P_ARR(NAME,...) PGM_P const NAME[] PROGMEM = { __VA_ARGS__ }

P_STR( token_001, "root"       );
P_STR( token_002, "adverb"     );
P_STR( token_003, "relation"   );
P_STR( token_004, "derog"      );
P_ARR(tokens,token_001,token_002,token_003,token_004);

P_STR( root_001, "You smell"  );
P_STR( root_002, "Rack off"   );
P_STR( root_003, "Stupid!"    );
P_STR( root_004, "Bugger off you %derog%" );
P_STR( root_005, "You %derog%"  );
P_STR( root_006, "%derog%!"     );
P_ARR(roots, root_001,root_002,root_003,root_004,root_005,root_006);

P_STR( derog_001, "idiot" );
P_STR( derog_002, "fool" );
P_STR( derog_003, "nincompoop" );
P_STR( derog_004, "loser" );
P_STR( derog_005, "twit" );
P_STR( derog_006, "twat" );
P_STR( derog_007, "wanker" );
P_STR( derog_008, "muppet" );
P_ARR(derog,derog_001,derog_002,derog_003,derog_004,derog_005,derog_006,derog_007,derog_008);