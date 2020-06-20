
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998_OAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998_OAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );


  }

  Nygren_1998_OAssignmentProcess()
  {
    // do nothing
  }



  virtual void initialize()
  {
    Process::initialize();

    dOCdt  = getVariableReference( "dOCdt" ).getVariable();
    dOTCdt  = getVariableReference( "dOTCdt" ).getVariable();
    dOTMgCdt  = getVariableReference( "dOTMgCdt" ).getVariable();
    O_C  = getVariableReference( "O_C" ).getVariable();
    O_TC  = getVariableReference( "O_TC" ).getVariable();
    O_TMgC  = getVariableReference( "O_TMgC" ).getVariable();
    O_TMgMg  = getVariableReference( "O_TMgMg" ).getVariable();
    Ca_i  = getVariableReference( "Ca_i" ).getVariable();

  }

  virtual void fire()
  {
    Ca_i_mM = Ca_i->getMolarConc()*1000.0;
    O_C_value = O_C->getValue();
    O_TC_value = O_TC->getValue();
    O_TMgC_value = O_TMgC->getValue();
    dOCdt->setValue( 1 * (200000.0*Ca_i_mM*(1.00000-O_C_value)-476.000*O_C_value) );
    dOTCdt->setValue( 1 * (78400.0*Ca_i_mM*(1.00000-O_TC_value)-392.000*O_TC_value) );
    dOTMgCdt->setValue( 1 * (200000.0*Ca_i_mM*((1.00000-O_TMgC_value)-O_TMgMg->getValue())-6.60000*O_TMgC_value) );

  }

 protected:

  Variable* dOCdt;
  Variable* dOTCdt;
  Variable* dOTMgCdt;
  Variable* O_C;
  Variable* O_TC;
  Variable* O_TMgC;
  Variable* O_TMgMg;
  Variable* Ca_i;

  Real Ca_i_mM;
  Real O_C_value;
  Real O_TC_value;
  Real O_TMgC_value;
};

LIBECS_DM_INIT( Nygren_1998_OAssignmentProcess, Process );
