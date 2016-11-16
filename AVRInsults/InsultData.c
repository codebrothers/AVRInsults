/*
 * InsultData.c
 *
 * Created: 16/11/2016 6:36:37 PM
 *  Author: Chris
 */ 

#include <avr/pgmspace.h>

#define P_STRING(NAME,STRING) char const NAME[] PROGMEM = STRING
#define P_ARRAY(NAME,...) PGM_P const NAME[] PROGMEM = { __VA_ARGS__ }

P_STRING( token_001, "root"       );
P_STRING( token_002, "adverb"     );
P_STRING( token_003, "relation"   );
P_STRING( token_004, "derog"      );
P_ARRAY(tokens,token_001,token_002,token_003,token_004);

P_STRING( root_001, "You smell"  );
P_STRING( root_002, "Rack off"   );
P_STRING( root_003, "Stupid!"    );
P_STRING( root_004, "Bugger off you %derog%" );
P_STRING( root_005, "You %derog%"  );
P_STRING( root_006, "%derog%!"     );
P_ARRAY(roots, root_001, root_002, root_003, root_004, root_005, root_006);
