
#include "libecs.hpp"
#include "ContinuousProcess.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998v_O_CalseFluxProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998v_O_CalseFluxProcess, Process )
  {
    INHERIT_PROPERTIES( Process );


  }

  Nygren_1998v_O_CalseFluxProcess()
  {
    // do nothing
  }



  virtual void initialize()
  {
    Process::initialize();

    O_Calse  = getVariableReference( "O_Calse" ).getVariable();
    v_O_Calse  = getVariableReference( "v_O_Calse" ).getVariable();

  }

  virtual void fire()
  {
    setFlux( v_O_Calse->getValue() );
  }

 protected:

  Variable* O_Calse;
  Variable* v_O_Calse;


};

LIBECS_DM_INIT( Nygren_1998v_O_CalseFluxProcess, Process );
