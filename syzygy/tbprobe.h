#ifndef TBPROBE_H
#define TBPROBE_H

#include "../zoeken.h"

void syzygy_path_init(const std::string& path);
int syzygy_probe_wdl(Stelling& pos, int *success);
int syzygy_probe_dtz(Stelling& pos, int *success);
extern int TBnum_piece, TBnum_pawn, TBmax_men;

#endif // #ifndef TBPROBE_H
