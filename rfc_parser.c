#include "rfc_parser.h"
#include <string.h>
#include <stdlib.h>

int parse_rfc_priority(const char* rfc_string) {
    /* Basit bir string parse iþlemi: "u=X" formatýndan X'i çeker */
    char* pos = strstr(rfc_string, "u=");
    if (pos) {
        return atoi(pos + 2); /* u= ifadesinden sonraki rakamý döner */
    }
    return 7; /* Varsayýlan en düþük öncelik */
}
