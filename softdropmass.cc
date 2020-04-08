typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > LorentzVector;

int softdropmass(){
	TChain *data=new TChain("t_ss");
	data->Add("/home/yulunmiao/Documents/CMS_data/WWWto2lFatJet/data/2018/*");
	vector<LorentzVector> *p4=0;
	int njet30;
	vector<float> *m=0;
	data->SetBranchAddress("ak8jets_p4",&p4);
	data->SetBranchAddress("nj30",&njet30);
	data->SetBranchAddress("ak8jets_softdropMass",&m);

	TH1F *h=new TH1F("","",100,0,200);
	for(int i=0;i<data->GetEntries();i++){
		data->GetEntry(i);
		if(njet30!=1) continue;
		if(m->size()!=1) continue;
		if(p4->at(0).Pt()<150) continue;
		h->Fill(m->at(0));
	}
	h->GetXaxis()->SetTitle("M_{j}");
	h->Draw();
	return 0;
}
