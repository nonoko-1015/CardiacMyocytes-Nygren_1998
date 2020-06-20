
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998dOCdtAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998dOCdtAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );


  }

  Nygren_1998dOCdtAssignmentProcess()
  {
    // do nothing
  }



  virtual void initialize()
  {
    Process::initialize();

    dOCdt  = getVariableReference( "dOCdt" ).getVariable();
    O_C  = getVariableReference( "O_C" ).getVariable();
    Ca_i  = getVariableReference( "Ca_i" ).getVariable();

  }

  virtual void fire()
  {
    dOCdt->setValue( 1 * (200000.0*(Ca_i->getMolarConc()*1000)*(1.00000-O_C->getValue())-476.000*O_C->getValue()) );

  }

 protected:

  Variable* dOCdt;
  Variable* O_C;
  Variable* Ca_i;


};

LIBECS_DM_INIT( Nygren_1998dOCdtAssignmentProcess, Process );
