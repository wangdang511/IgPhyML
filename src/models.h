/*

codonPHYML: a program that  computes maximum likelihood phylogenies from
CODON homologous sequences.

Copyright (C) Marcelo Serrano Zanetti. Oct 2010 onward.

built upon

PHYML :  a program that  computes maximum likelihood  phylogenies from
DNA or AA homologous sequences 

Copyright (C) Stephane Guindon. Oct 2003 onward

All parts of  the source except where indicated  are distributed under
the GNU public licence.  See http://www.opensource.org for details.

*/

#ifndef MODELS_H
#define MODELS_H

#include "utilities.h"
#include "eigen.h"
#include "free.h"
#include "stats.h"

void PMat(phydbl l, model *mod, int pos, phydbl *Pij);
void PMat_K80(phydbl l,phydbl kappa, int pos, phydbl *Pij);
void PMat_TN93(phydbl l, model *mod, int pos, phydbl *Pij);
void PMat_Empirical(phydbl l, model *mod, int pos, phydbl *Pij);
void PMat_Zero_Br_Len(model  *mod, int pos, phydbl *Pij);
void PMat_Gamma(phydbl l, model *mod, int pos, phydbl *Pij);

int GetDaa (phydbl *daa, phydbl *pi, char *file_name);
void Init_Model(calign *data, model *mod, option *io);
void Update_Qmat_GTR(phydbl *rr, phydbl *rr_val, int *rr_num, phydbl *pi, phydbl *qmat);
void Update_Qmat_HKY(phydbl kappa, phydbl *pi, phydbl *qmat);
void Update_Qmat_Generic(phydbl *rr, phydbl *pi, int ns, phydbl *qmat);
void Translate_Custom_Mod_String(model *mod);
void Set_Model_Parameters(model *mod);
phydbl GTR_Dist(phydbl *F, phydbl alpha, eigen *eigen_struct);
phydbl General_Dist(phydbl *F, model *mod, eigen *eigen_struct);

int Init_Qmat_WAG(phydbl *daa, phydbl *pi);
int Init_Qmat_Dayhoff(phydbl *daa, phydbl *pi);
int Init_Qmat_JTT(phydbl *daa, phydbl *pi);
int Init_Qmat_RtREV(phydbl *daa, phydbl *pi);
int Init_Qmat_CpREV(phydbl *daa, phydbl *pi);
int Init_Qmat_VT(phydbl *daa, phydbl *pi);
int Init_Qmat_Blosum62(phydbl *daa, phydbl *pi);
int Init_Qmat_MtMam(phydbl *daa, phydbl *pi);
int Init_Qmat_MtArt(phydbl *daa, phydbl *pi); // Added by Federico Abascal
int Init_Qmat_HIVb(phydbl *daa, phydbl *pi);  // Added by Federico Abascal
int Init_Qmat_HIVw(phydbl *daa, phydbl *pi);  // Added by Federico Abascal
void Switch_From_Mod_To_M4mod(model *mod);
void Switch_From_M4mod_To_Mod(model *mod);
void PMat_JC69(phydbl l, int pos, phydbl *Pij, model *mod);

phydbl F1x4(int codon, phydbl *f); //!<Added by Marcelo.
phydbl F3x4(int codon, phydbl *freq ); //!<Added by Marcelo.
phydbl Omega_ECMtoMmechModels(phydbl *pi, phydbl *qmat, phydbl *qmatbuff, int numSensecodons, int n_w_catg); //!<Added by Marcelo.
phydbl Scale_Q_MatrixManyOmegaModels(phydbl *qmat, phydbl *pi, phydbl *freq, int n_w_catg, int numSenseCodons, model *mod); //!<Added by Marcelo. 
void EqFrequencies(int modfreq, phydbl *pi, phydbl *freq, int numSensecodons); //!<Added by Marcelo.
void  PMat_CODON(phydbl l, model *mod, int pos, phydbl *Pij); //!<Added by Marcelo.
void  PMat_CODON_part(phydbl l, model *mod, int pos, phydbl *Qmat, phydbl *Pij,int modeli); //!<Added by Marcelo. //updated by Ken  22/8
void PMat_CODON_Pairwise(phydbl l, phydbl *Pij,  phydbl *U, phydbl *V, phydbl *R, int n, phydbl *uexpt, phydbl *expt); //!<Added by Marcelo.
void PadeApprox(int n, int nn, phydbl *A, model *mod, phydbl *F, int pos, phydbl len, int m, int modeli); //!<Added by Marcelo. Updated by Ken 22/8

// stefan:
phydbl Update_Qmat_Codons(model *mod, int cat, int modeli);
void Update_Qmat_HLP16( phydbl *mat, phydbl *qmat, phydbl * freqs, int cat, model *mod,phydbl omega);
void Update_Qmat_GY( phydbl *mat, phydbl *qmat, phydbl * freqs, int cat, model *mod);
void Update_Qmat_MG( phydbl *mat, phydbl *qmat, phydbl * freqs, int cat, model *mod);
void Update_Qmat_YAP( phydbl *mat, phydbl *qmat, phydbl * freqs, int cat, model *mod);
phydbl Kappa_Omega_Factor( int senseCodoni, int senseCodonj, model *mod, int cat,phydbl omega);

void Update_Rate_Matrix_PCAModel( model *mod ); //!<Added by Marcelo.

phydbl Scale_P_MatrixManyOmegaModels(phydbl *Pij,  phydbl *pi, phydbl *freq, int n_w_catg, int numSenseCodons, model *mod); //!< Added by Marcelo.

void print_matrix(phydbl *mat, int ns, char *s,int row); //!< Added by Marcelo.
void print_array(phydbl *array, int ns, char *s); //!< Added by Marcelo.
extern phydbl ecmK07[61][61]; //!<Added by Marcelo.
extern phydbl ecmK07freq[61]; //!<Added by Marcelo.
extern phydbl ecmS05[64][64]; //!<Added by Marcelo.
extern phydbl ecmS05freq[64]; //!<Added by Marcelo.
extern phydbl pcaM[61][61]; //!<Added by Marcelo.
extern phydbl pcaP[372100]; //!<Added by Marcelo.
extern phydbl pcaS[61][61]; //!<Added by Marcelo.
extern phydbl pcafreq[61]; //!<Added by Marcelo.

#define flow 0.001 //!<Added by Marcelo.
#define fhigh 0.999 //!<Added by Marcelo.

#ifndef MACOS
extern phydbl dlange_(char *norm, int *m, int *n, phydbl *A, int *lda, phydbl * work); //!<Added by Marcelo.
extern void dgesv_(int * N, int * NRHS, phydbl *A, int *LDA, int *IPIV, phydbl * B, int *LDB, int *INFO); //!<Added by Marcelo.
#endif
#endif
