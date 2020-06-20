
#include "libecs.hpp"
#include "ContinuousProcess.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998v_O_CFluxProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998v_O_CFluxProcess, Process )
  {
    INHERIT_PROPERTIES( Process );


  }

  Nygren_1998v_O_CFluxProcess()
  {
    // do nothing
  }



  virtual void initialize()
  {
    Process::initialize();

    O_C  = getVariableReference( "O_C" ).getVariable();
    dOCdt  = getVariableReference( "dOCdt" ).getVariable();

  }

  virtual void fire()
  {
    setFlux( dOCdt->getValue() );
  }

 protected:

  Variable* O_C;
  Variable* dOCdt;


};

LIBECS_DM_INIT( Nygren_1998v_O_CFluxProcess, Process );
