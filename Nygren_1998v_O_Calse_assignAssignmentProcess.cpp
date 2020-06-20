
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998v_O_Calse_assignAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998v_O_Calse_assignAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );


  }

  Nygren_1998v_O_Calse_assignAssignmentProcess()
  {
    // do nothing
  }



  virtual void initialize()
  {
    Process::initialize();

    v_O_Calse  = getVariableReference( "v_O_Calse" ).getVariable();
    O_Calse  = getVariableReference( "O_Calse" ).getVariable();
    Ca_rel  = getVariableReference( "Ca_rel" ).getVariable();

  }

  virtual void fire()
  {
    v_O_Calse->setValue( 1 * (480.000*(Ca_rel->getMolarConc()*1000)*(1.00000-O_Calse->getValue())-400.000*O_Calse->getValue()) );

  }

 protected:

  Variable* v_O_Calse;
  Variable* O_Calse;
  Variable* Ca_rel;


};

LIBECS_DM_INIT( Nygren_1998v_O_Calse_assignAssignmentProcess, Process );
