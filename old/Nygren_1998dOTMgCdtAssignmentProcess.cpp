
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998dOTMgCdtAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998dOTMgCdtAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );


  }

  Nygren_1998dOTMgCdtAssignmentProcess()
  {
    // do nothing
  }



  virtual void initialize()
  {
    Process::initialize();

    dOTMgCdt  = getVariableReference( "dOTMgCdt" ).getVariable();
    O_TMgC  = getVariableReference( "O_TMgC" ).getVariable();
    Ca_i  = getVariableReference( "Ca_i" ).getVariable();
    O_TMgMg  = getVariableReference( "O_TMgMg" ).getVariable();

  }

  virtual void fire()
  {
    dOTMgCdt->setValue( 1 * (200000.0*(Ca_i->getMolarConc()*1000)*((1.00000-O_TMgC->getValue())-O_TMgMg->getValue())-6.60000*O_TMgC->getValue()) );

  }

 protected:

  Variable* dOTMgCdt;
  Variable* O_TMgC;
  Variable* Ca_i;
  Variable* O_TMgMg;


};

LIBECS_DM_INIT( Nygren_1998dOTMgCdtAssignmentProcess, Process );
