
#include "FLAME.h"

extern fla_apcaq2ut_t* flash_apcaq2ut_cntl;

fla_apcaqutinc_t*      flash_apcaqutinc_cntl;
fla_blocksize_t*       flash_apcaqutinc_var1_bsize;

void FLASH_Apply_CAQ_UT_inc_cntl_init()
{
	// Set blocksizes for hierarchical storage.
	flash_apcaqutinc_var1_bsize = FLA_Blocksize_create( 1, 1, 1, 1 );

	// Create a control tree to invoke variant 1.
	flash_apcaqutinc_cntl = FLA_Cntl_apcaqutinc_obj_create( FLA_HIER,
	                                                        FLA_BLOCKED_VARIANT1, 
	                                                        flash_apcaqutinc_var1_bsize,
	                                                        flash_apcaq2ut_cntl );
}

void FLASH_Apply_CAQ_UT_inc_cntl_finalize()
{
	FLA_Cntl_obj_free( flash_apcaqutinc_cntl );

	FLA_Blocksize_free( flash_apcaqutinc_var1_bsize );
}
