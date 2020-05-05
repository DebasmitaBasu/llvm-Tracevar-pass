#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/InstrTypes.h"
#include "llvm/IR/Metadata.h"
#include "llvm/IR/Use.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Instruction.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DataLayout.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/DebugInfoMetadata.h"
#include "llvm/IR/Module.h"
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>


using namespace llvm;

namespace {


  struct TracevarPass : public FunctionPass {
    static char ID;
    std::unordered_map <llvm::Instruction*, int> holdalloca;
                                              
    TracevarPass() : FunctionPass(ID) {}

 
    virtual bool runOnFunction(Function &F) override {
    
    // int LCount= -1;
    // int SCount= -1;
        
    // int allocacnt = -1;

    
    for (auto& B : F) {

        for(Instruction &I: B){

            if(I.getOpcode() == Instruction::Alloca)
               errs()<<"Alloca:"<<I<<"\n";
            
            if (isa<CallInst>(I)) {

            
            	// if(I.getOpcode() == 54)
            	//   errs()<<I<<I.getOpcode()<<"\n ";
     
                StringRef calledFN = cast<CallInst>(I).getCalledFunction()->getName();


                //errs()<<calledFN<<"\n ";
                if(calledFN == "llvm.dbg.declare" ){

                    //Holding alloca function call instructions
                    //std::unordered_map<llvm::Instruction*, int>::const_iterator search = holdalloca.find(&I);

                    //if(search == holdalloca.end()){

                        //allocacnt+=1;
                        //if(I.getOpcode() == Instruction::Alloca){
                          // errs()<<"Alloca:"<<I<<"\n";
                        
                    
                        errs()<<I<<"|Instruction Op code "<<I.getOpcode()<<"|"<<I.getOperand(0)<<","<<I.getOperand(1)<<"\n";
                        
                        Instruction *II = &I;
                        CallInst *CI = dyn_cast<CallInst>(II);
						//CallInst *CI = &I;  /* Call to llvm.dbg.declare */
						AllocaInst *AI, *AII;    /* AllocaInst is the result */
                        
						Metadata *Meta = cast<MetadataAsValue>(CI->getOperand(1))->getMetadata();
                        Metadata *Meta1 = cast<MetadataAsValue>(CI->getOperand(2))->getMetadata();
                        
                        // errs()<<Meta->getName()<<"\n ";
                        // errs()<<Meta1->getName()<<"\n ";
						
						if (isa<ValueAsMetadata>(Meta)) {
							Value *V = cast <ValueAsMetadata>(Meta)->getValue();
							AI = cast<AllocaInst>(V);

							//errs()<<"meta:"<<(Meta)<<"\n";
							//StringRef s=cast<CallInst>(AI).getCalledFunction()->getName();
							//errs()<<V->getOperand(0)<<"\n ";
						}

                        if (isa<ValueAsMetadata>(Meta1)) {
                            Value *V1 = cast <ValueAsMetadata>(Meta1)->getValue();
                            AII = cast<AllocaInst>(V1);

                            //errs()<<"meta:"<<(Meta)<<"\n";
                            //StringRef s=cast<CallInst>(AI).getCalledFunction()->getName();
                            //errs()<<V->getOperand(0)<<"\n ";
                        }

                        

						DIVariable *V = cast<DIVariable>(cast<MetadataAsValue>(CI->getOperand(1))->getMetadata());
                        DIVariable *V1 = cast<DIVariable>(cast<MetadataAsValue>(CI->getOperand(2))->getMetadata());


                        //StringRef varname = V->getName();
                        

                        if(V!=NULL)
                           errs()<<V->getName()<<"\n ";
                           errs()<<V->getLine()<<"\n ";
                           errs()<<V->getDirectory()<<"\n ";
                           errs()<<V->getFilename()<<"\n ";

                        if(V1!=NULL)
                           errs()<<V1->getName()<<"\n ";

                        //std::string s = "Instruction"+I;
                        //errs()<<"s";

                        // Value* m1=I.getOperand(0);
                        // Value* m2=I.getOperand(1);

                    //     holdalloca[&I] = 1;
                    // }
                    // else{
                        
                    //     holdalloca[&I] += 1;
                    // }

                    //I.dump();
                }
            //}
            }else{

                //-----------------------------------------------------------------
                    // if(I.getOpcode() == Instruction::Load){
                    //         //errs()<<"hereload";
                    //         LCount += 1;
                    //         errs()<<"Load ("<<LCount<<"):"<<I<<"\n";
                    //     }
                    // if(I.getOpcode() == Instruction::Store){
                    //         //errs()<<"herestore";
                    //         SCount += 1;
                    //         errs()<<"Store ("<<SCount<<"):"<<I<<"\n";
                                
                    //     }
                //----------------------------------------------------------------------------------
                    //std::unordered_map<llvm::Instruction*, int>::const_iterator b = holdalloca.begin();
                    //std::unordered_map<llvm::Instruction*, int>::const_iterator e = holdalloca.end();
                    //while( b != e ){
                      //  for (auto m = I.op_begin(); m!=I.op_end();++m){

                                //errs()<<"autom"<<m<<"\n";

                                //Printing Load Instructions of alloca data objects
                                //if(I.getOpcode() == Instruction::Alloca){
                                 //   auto* LI = dyn_cast<LoadInst>(&I);  
                                    
                                    
                                          
        
                                        //std::unordered_map<llvm::Instruction*, int>::const_iterator search = holdalloca.find(LI);
                                        // if(search == holdalloca.end()){
                                        //     //errs()<<I.getOperand(0)<<"::"<<I.getOperand(1)<<"\n";
                                            
                                            
                                        //     //LCount += 1;
                                        //     errs()<<"Load<"<<LCount<<">"<<I<<" : "<<"|"<<I.getOperand(0)<<","<<I.getOperand(1)<<"\n";
                                        //     holdalloca[LI] = 1;
                                            
                                        // }
                                        // else{
                                        //     holdalloca[LI] += 1;
                                        // } 
                                    
                                //}
                                //else{ 

                                    //Printing Store Instructions of alloca data objects
                                    // if(I.getOpcode() == Instruction::Store){
                                    //     auto* SI = dyn_cast<StoreInst>(&I);

                                    //     std::unordered_map<llvm::Instruction*, int>::const_iterator search = holdalloca.find(SI);
                                    //     if(search == holdalloca.end()){
                                    //         //SCount += 1;
                                    //         //errs()<<I.getOperand(0)<<"::"<<I.getOperand(1)<<"\n";
                                            
                                    //         errs()<<"Store<"<<SCount<<">"<<I<<" : "<<"|"<<I.getOperand(0)<<","<<I.getOperand(1)<<"\n";
                                    //         holdalloca[SI] = 1;
                            
                                    //     }
                                    //     else{
                                    //         holdalloca[SI] += 1;
                                
                                    //     } 
                                    // }
                                //}

                           //}
                        // }       
                       
                      // b++;

                    //}   
                
                }        


            }

        

             
    }


         return false;
    }
  
 };

}


char TracevarPass::ID = 0;

static RegisterPass<TracevarPass> X("assn2-pass", "Display alloca data objects",
    false /* Only looks at CFG */,
    false /* Analysis Pass */);


static RegisterStandardPasses Y(
    PassManagerBuilder::EP_EarlyAsPossible,
    [](const PassManagerBuilder &Builder,
      legacy::PassManagerBase &PM) { PM.add(new TracevarPass()); });

