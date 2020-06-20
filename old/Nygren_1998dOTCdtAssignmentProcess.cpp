
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998dOTCdtAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998dOTCdtAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );


  }

  Nygren_1998dOTCdtAssignmentProcess()
  {
    // do nothing
  }



  virtual void initialize()
  {
    Process::initialize();

    dOTCdt  = getVariableReference( "dOTCdt" ).getVariable();
    O_TC  = getVariableReference( "O_TC" ).getVariable();
    Ca_i  = getVariableReference( "Ca_i" ).getVariable();

  }

  virtual void fire()
  {
    dOTCdt->setValue( 1 * (78400.0*(Ca_i->getMolarConc()*1000)*(1.00000-O_TC->getValue())-392.000*O_TC->getValue()) );

  }

 protected:

  Variable* dOTCdt;
  Variable* O_TC;
  Variable* Ca_i;


};

LIBECS_DM_INIT( Nygren_1998dOTCdtAssignmentProcess, Process );
